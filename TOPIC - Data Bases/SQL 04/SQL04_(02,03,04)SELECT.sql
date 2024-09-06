--Задача №2
-- 1
select "name", duration from track
order by duration desc
limit 1;

-- 2
select "name" from track
where duration >= '00:03:30';

-- 3
select "name" from compilation
where release_year between 2018 and 2020;

-- 4
select performer from performer
where performer not like '% %' and performer not like '%/%' and performer not like '%-%';

-- 5
select "name" from track
where LOWER("name") like '% my %' or LOWER("name") like '% мой %' or LOWER("name") like 'my %' or  LOWER("name") like 'мой %' or LOWER("name") like '% my' or  LOWER("name") like '% мой';
--Конец

-- Задача №3
-- 1
select genre.category, count(performergenre.performer_id) from genre 
join performergenre on genre.id = performergenre.genre_id
group by genre.category;

-- 2
select album."name", count(album_id) from track
join album on album_id = album.id 
where album.release_year between 2019 and 2020
group by album."name";

-- 3
-- Здесь небольшая проблемка, у меня по одному треку в каждом альбоме поэтому он не может выдать среднюю продолжительность. 
-- Но так как сам код вроде как верный и условие "результаты запросов не должны быть пустыми" выполнено. Мне кажется это не критично.
-- Эсли нет, и нужно чтобы обязятельно было несколько треков в каждом альбоме. Тогда я без проблем переделаю)
select album."name", avg(track.duration) from track
join album on album_id = album.id 
group by album."name";

-- 4
--Сначала я написал этот код. Но он не подходит потому что исполнитель выпустил несколько альбомов и один из них в 2020 а другой нет.
select performer.performer from performer
join performeralbum on performer.id = performeralbum.performer_id
join album on performeralbum.album_id = album.id
where album.release_year != 2020
group by performer.performer;
-- поэтому я написал второй вариант у меня от него немного голова кружиться но работает вроде верно :)
select distinct performer.performer from performer 
where performer.id not in (
	select distinct performer.id from performer
	join performeralbum on performer.id = performeralbum.performer_id
	join album on performeralbum.album_id = album.id 
	where album.release_year = '2020'
); 

-- 5
select compilation."name" from compilation 
join compilationtrack on compilationtrack.compilation_id = compilation.id
join track on track.id = compilationtrack.track_id  
join album on album.id = track.album_id
join performeralbum on performeralbum.album_id = album.id 
join performer on performer.id = performeralbum.performer_id 
where performer.performer = 'Бритни Спирс';
--Конец

-- Задача №4
-- 1
SELECT album.name FROM album
JOIN performeralbum ON album.id = performeralbum.album_id
JOIN performer ON performeralbum.performer_id = performer.id
JOIN performergenre ON performer.id = performergenre.performer_id
GROUP BY album.name
HAVING COUNT(DISTINCT performergenre.genre_id) > 1;

-- 2
SELECT track.name FROM track
LEFT JOIN compilationtrack ON track.id = compilationtrack.track_id
WHERE compilationtrack.track_id IS NULL;

-- 3
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

-- 4
WITH track_count AS (
    SELECT album.id, COUNT(track.id) AS track_count FROM album
    JOIN track ON album.id = track.album_id
    GROUP BY album.id
)
SELECT album.name FROM album
JOIN track_count ON album.id = track_count.id
WHERE track_count.track_count = (
    SELECT MIN(track_count) FROM track_count
);
--Конец
