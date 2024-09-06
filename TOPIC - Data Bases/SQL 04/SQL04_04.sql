--Задание 1
SELECT album.name FROM album
JOIN performeralbum ON album.id = performeralbum.album_id
JOIN performer ON performeralbum.performer_id = performer.id
JOIN performergenre ON performer.id = performergenre.performer_id
GROUP BY album.name
HAVING COUNT(DISTINCT performergenre.genre_id) > 1;

--Задание 2
SELECT track.name 
FROM track
LEFT JOIN compilationtrack ON track.id = compilationtrack.track_id
WHERE compilationtrack.track_id IS NULL;

--Задание 3
WITH shortest_track AS (
    SELECT duration FROM track 
    ORDER BY duration ASC 
    LIMIT 1
)
SELECT DISTINCT performer.performer FROM performer
JOIN performeralbum ON performer.id = performeralbum.performer_id
JOIN album ON performeralbum.album_id = album.id
JOIN track ON album.id = track.album_id
WHERE track.duration = (SELECT duration FROM shortest_track);

--Задание 4
WITH track_count AS (
    SELECT album.id, COUNT(track.id) AS track_count FROM album
    JOIN track ON album.id = track.album_id
    GROUP BY album.id
)
SELECT album.name FROM album
JOIN track_count ON album.id = track_count.id
WHERE track_count.track_count = (
    SELECT MIN(track_count) 
    FROM track_count
);
