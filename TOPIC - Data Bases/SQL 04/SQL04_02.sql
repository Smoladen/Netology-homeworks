--Задание 1
select "name", duration from track
order by duration desc
limit 1;

--Задание 2
select "name" from track
where duration >= '00:03:30';

--Задание 3
select "name" from compilation
where release_year between 2018 and 2020;

--Задание 4
select performer from performer
where performer not like '% %' and performer not like '%/%' and performer not like '%-%';

--Задание 5
select "name" from track
where LOWER("name") like '% my %' or LOWER("name") like '% мой %' or LOWER("name") like 'my %' or  LOWER("name") like 'мой %' or LOWER("name") like '% my' or  LOWER("name") like '% мой';
