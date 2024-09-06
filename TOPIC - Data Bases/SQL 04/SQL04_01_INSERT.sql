
insert into genre(category)
values('Метал'),('Поп'),('Рок');

insert into performer(performer)
values('System of a Down'),('Ария'),('Iron Maiden'),('Бритни Спирс'),('AC/DC'),('Skillet');

insert into performergenre(performer_id, genre_id)
values('1', '1'),('1', '3'),('2', '1'),('3', '1'),('3', '3'),('4', '2'),('5', '3'),('6', '3');

insert into album("name", release_year)
values('Toxicity', '2001'),('Hypnotyse', '2005'),('Химера', '2001'),('Армагедон', '2006'),('Fear of the Dark', '1992'),('Circus', '2008'),('Back in Black', '1980'),('Skillet', '1996'),('Victorious', '2019');

insert into performeralbum(performer_id , album_id)
values('1', '1'),('1', '2'),('1', '3'),('2', '4'),('2', '5'),('3', '6'),('3', '2'),('4', '6'),('5', '7'),('5', '6'),('6', '8'),('6', '9');

insert into track(album_id , "name", duration)
values('1','My Prison Song','00:03:21'),('2','Attack','00:03:06'),('3','Химера','00:04:39'),('4','Мой Страж Исперии','00:04:44'),('5','Fear of the Dark','00:07:19'),('6','Womanizer','00:03:43'),('7','Shake a Leg','00:04:05'),('8','Gasoline','00:4:02'),('9','Legendary','00:04:04');

insert into compilation("name", release_year)
valuse('Полёт','2009'),('Four Minutes','2020'),('Три','2018'),('OLd','1997');

insert into compilationtrack (compilation_id , track_id)
values('1', '3'),('1', '8'),('2', '7'),('2', '8'),('2', '9'),('3', '1'),('3', '2'),('3', '6'),('4', '5'),('4', '7'),('4', '8');