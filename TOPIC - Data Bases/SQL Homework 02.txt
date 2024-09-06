-- Genre Table
CREATE TABLE IF NOT EXISTS Genre(
    id SERIAL PRIMARY KEY,
    category TEXT
);

-- Performer Table
CREATE TABLE IF NOT EXISTS Performer(
    id SERIAL PRIMARY KEY,
    performer TEXT
);

-- PerformerGenre Table for many-to-many relationship between Performer and Genre
CREATE TABLE IF NOT EXISTS PerformerGenre(
    performer_id INTEGER NOT NULL REFERENCES Performer(id),
    genre_id INTEGER NOT NULL REFERENCES Genre(id),
    CONSTRAINT pk_performer_genre PRIMARY KEY (performer_id, genre_id)
);

-- Album Table
CREATE TABLE IF NOT EXISTS Album(
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    release_year INTEGER
);

-- Track Table
CREATE TABLE IF NOT EXISTS Track(
    id SERIAL PRIMARY KEY,
    album_id INTEGER NOT NULL REFERENCES Album(id),
    name VARCHAR(100) NOT NULL,
    duration TIME
);

-- Compilation Table
CREATE TABLE IF NOT EXISTS Compilation(
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    release_year INTEGER
);

-- PerformerAlbum Table for many-to-many relationship between Performer and Album
CREATE TABLE IF NOT EXISTS PerformerAlbum(
    performer_id INTEGER NOT NULL REFERENCES Performer(id),
    album_id INTEGER NOT NULL REFERENCES Album(id),
    CONSTRAINT pk_performer_album PRIMARY KEY (performer_id, album_id)
);

-- CompilationTrack Table for many-to-many relationship between Compilation and Track
CREATE TABLE IF NOT EXISTS CompilationTrack(
    compilation_id INTEGER NOT NULL REFERENCES Compilation(id),
    track_id INTEGER NOT NULL REFERENCES Track(id),
    CONSTRAINT pk_compilation_track PRIMARY KEY (compilation_id, track_id)
);
