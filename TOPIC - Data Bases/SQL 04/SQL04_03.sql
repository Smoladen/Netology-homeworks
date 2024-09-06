-- Задание 1
select genre.category, count(performergenre.performer_id) from genre 
join performergenre on genre.id = performergenre.genre_id
group by genre.category;

-- Задание 2
select album."name", count(album_id) from track
join album on album_id = album.id 
where album.release_year between 2019 and 2020
group by album."name";

-- Задание 3
-- Здесь небольшая проблемка, у меня по одному треку в каждом альбоме поэтому он не может выдать среднюю продолжительность. 
-- Но так как сам код вроде как верный и условие "результаты запросов не должны быть пустыми" выполнено. Мне кажется это не критично.
-- Эсли нет, и нужно чтобы обязятельно было несколько треков в каждом альбоме. Тогда я без проблем переделаю)
select album."name", avg(track.duration) from track
join album on album_id = album.id 
group by album."name";

-- Задание 4
--Сначало я написал этот код. Но он не подходит потому что исполнитель выпустил несколько альбомов и один из них в 2020 а другой нет.
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

--Задание 5
select compilation."name" from compilation 
join compilationtrack on compilationtrack.compilation_id = compilation.id
join track on track.id = compilationtrack.track_id  
join album on album.id = track.album_id
join performeralbum on performeralbum.album_id = album.id 
join performer on performer.id = performeralbum.performer_id 
where performer.performer = 'Бритни Спирс';

