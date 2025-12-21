SELECT DISTINCT people.name
FROM people
JOIN stars ON stars.person_id = people.id
WHERE stars.movie_id IN (
    SELECT movies.id
    FROM movies
    JOIN stars ON stars.movie_id = movies.id
    WHERE stars.person_id = (
        SELECT id
        FROM people
        WHERE name = 'Kevin Bacon' AND birth = 1958
    )
)
AND people.id <> (
    SELECT id
    FROM people
    WHERE name = 'Kevin Bacon' AND birth = 1958
);

