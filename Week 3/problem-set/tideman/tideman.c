#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
bool detect_cycle(int v);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // Selection Sort
    for (int i = 0; i < pair_count; i++)
    {
        int bigger_i = i;
        int pair_i = preferences[pairs[bigger_i].winner][pairs[bigger_i].loser];
        for (int j = i + 1; j < pair_count; j++)
        {
            int pair_j = preferences[pairs[j].winner][pairs[j].loser];
            if (pair_j > pair_i)
            {
                bigger_i = j;
                pair_i = pair_j;
            }
        }
        if (bigger_i != i)
        {
            pair aux = pairs[i];
            pairs[i] = pairs[bigger_i];
            pairs[bigger_i] = aux;
        }
    }
    return;
}

// Kahn's algorithm, BFS
bool detect_cycle(int v)
{
    // Array to store in-degrees of all vertices
    int in_degree[MAX] = {0};

    // Compute in-degrees of all vertices
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (locked[i][j])
            {
                in_degree[j]++;
            }
        }
    }

    // Enqueue vertices with zero in-degrees
    int queue[MAX], front = 0, rear = 0;
    for (int i = 0; i < v; i++)
    {
        if (in_degree[i] == 0)
        {
            queue[rear++] = i;
        }
    }
    int count = 0;
    while (front < rear)
    {
        int u = queue[front++];
        count++;
        for (int i = 0; i < v; i++)
        {
            if (locked[u][i])
            {
                if (--in_degree[i] == 0)
                {
                    queue[rear++] = i;
                }
            }
        }
    }
    return count != v;
}
// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
        if (detect_cycle(candidate_count))
        {
            // Remove the vote if detect a cycle
            locked[pairs[i].winner][pairs[i].loser] = false;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // The winner will be the one without any one pointing to it, that is, degree 0
    for (int i = 0; i < candidate_count; i++)
    {
        bool is_source = true;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i])
            {
                is_source = false;
                break;
            }
        }
        if (is_source)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
    return;
}
