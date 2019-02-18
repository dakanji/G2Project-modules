## mysql
# R_TagsMap_1.0
DROP TABLE DB_TABLE_PREFIXTagsMap;

DELETE FROM DB_TABLE_PREFIXSchema WHERE DB_COLUMN_PREFIXname='TagsMap';

# R_Tags_1.0
DROP TABLE DB_TABLE_PREFIXTags;

DELETE FROM DB_TABLE_PREFIXSchema WHERE DB_COLUMN_PREFIXname='Tags';

# TagItemMap
CREATE TABLE DB_TABLE_PREFIXTagItemMap(
 DB_COLUMN_PREFIXitemId int(11),
 DB_COLUMN_PREFIXtagId int(11),
 PRIMARY KEY(DB_COLUMN_PREFIXitemId, DB_COLUMN_PREFIXtagId),
 INDEX DB_TABLE_PREFIXTagItemMap_57276(DB_COLUMN_PREFIXtagId)
) DB_TABLE_TYPE
/*!40100 DEFAULT CHARACTER SET utf8 */;

INSERT INTO DB_TABLE_PREFIXSchema (
 DB_COLUMN_PREFIXname,
 DB_COLUMN_PREFIXmajor,
 DB_COLUMN_PREFIXminor
) VALUES('TagItemMap', 1, 0);

# TagMap
CREATE TABLE DB_TABLE_PREFIXTagMap(
 DB_COLUMN_PREFIXtagId int(11) NOT NULL,
 DB_COLUMN_PREFIXtagName varchar(128) NOT NULL,
 PRIMARY KEY(DB_COLUMN_PREFIXtagId),
 UNIQUE (DB_COLUMN_PREFIXtagName)
) DB_TABLE_TYPE
/*!40100 DEFAULT CHARACTER SET utf8 */;

INSERT INTO DB_TABLE_PREFIXSchema (
 DB_COLUMN_PREFIXname,
 DB_COLUMN_PREFIXmajor,
 DB_COLUMN_PREFIXminor
) VALUES('TagMap', 1, 0);

## postgres
# R_TagsMap_1.0
DROP TABLE DB_TABLE_PREFIXTagsMap;

DELETE FROM DB_TABLE_PREFIXSchema WHERE DB_COLUMN_PREFIXname='TagsMap';

# R_Tags_1.0
DROP TABLE DB_TABLE_PREFIXTags;

DELETE FROM DB_TABLE_PREFIXSchema WHERE DB_COLUMN_PREFIXname='Tags';

# TagItemMap
CREATE TABLE DB_TABLE_PREFIXTagItemMap(
 DB_COLUMN_PREFIXitemId INTEGER,
 DB_COLUMN_PREFIXtagId INTEGER
);

ALTER TABLE DB_TABLE_PREFIXTagItemMap ADD PRIMARY KEY (DB_COLUMN_PREFIXitemId, DB_COLUMN_PREFIXtagId);

CREATE INDEX DB_TABLE_PREFIXTagItemMap_57276 ON DB_TABLE_PREFIXTagItemMap(DB_COLUMN_PREFIXtagId);

INSERT INTO DB_TABLE_PREFIXSchema (
 DB_COLUMN_PREFIXname,
 DB_COLUMN_PREFIXmajor,
 DB_COLUMN_PREFIXminor
) VALUES('TagItemMap', 1, 0);

# TagMap
CREATE TABLE DB_TABLE_PREFIXTagMap(
 DB_COLUMN_PREFIXtagId INTEGER NOT NULL,
 DB_COLUMN_PREFIXtagName VARCHAR(128) NOT NULL
);

ALTER TABLE DB_TABLE_PREFIXTagMap ADD PRIMARY KEY (DB_COLUMN_PREFIXtagId);

CREATE UNIQUE INDEX DB_TABLE_PREFIXTagMap_13536 ON DB_TABLE_PREFIXTagMap(DB_COLUMN_PREFIXtagName);

INSERT INTO DB_TABLE_PREFIXSchema (
 DB_COLUMN_PREFIXname,
 DB_COLUMN_PREFIXmajor,
 DB_COLUMN_PREFIXminor
) VALUES('TagMap', 1, 0);

## oracle
# R_TagsMap_1.0
DROP TABLE DB_TABLE_PREFIXTagsMap;

DELETE FROM DB_TABLE_PREFIXSchema WHERE DB_COLUMN_PREFIXname='TagsMap';

# R_Tags_1.0
DROP TABLE DB_TABLE_PREFIXTags;

DELETE FROM DB_TABLE_PREFIXSchema WHERE DB_COLUMN_PREFIXname='Tags';

# TagItemMap
CREATE TABLE DB_TABLE_PREFIXTagItemMap(
 DB_COLUMN_PREFIXitemId INTEGER,
 DB_COLUMN_PREFIXtagId INTEGER
);

CREATE INDEX DB_TABLE_PREFIXTagItemMap_57276
   ON DB_TABLE_PREFIXTagItemMap(DB_COLUMN_PREFIXtagId);

ALTER TABLE DB_TABLE_PREFIXTagItemMap
 ADD PRIMARY KEY (DB_COLUMN_PREFIXitemId, DB_COLUMN_PREFIXtagId)
;

INSERT INTO DB_TABLE_PREFIXSchema (
 DB_COLUMN_PREFIXname,
 DB_COLUMN_PREFIXmajor,
 DB_COLUMN_PREFIXminor
) VALUES('TagItemMap', 1, 0);

# TagMap
CREATE TABLE DB_TABLE_PREFIXTagMap(
 DB_COLUMN_PREFIXtagId INTEGER NOT NULL,
 DB_COLUMN_PREFIXtagName VARCHAR2(128) NOT NULL
);

ALTER TABLE DB_TABLE_PREFIXTagMap
 ADD PRIMARY KEY (DB_COLUMN_PREFIXtagId)
 ADD UNIQUE (DB_COLUMN_PREFIXtagName)
;

INSERT INTO DB_TABLE_PREFIXSchema (
 DB_COLUMN_PREFIXname,
 DB_COLUMN_PREFIXmajor,
 DB_COLUMN_PREFIXminor
) VALUES('TagMap', 1, 0);

## db2
# R_TagsMap_1.0
DROP TABLE DB_TABLE_PREFIXTagsMap;

DELETE FROM DB_TABLE_PREFIXSchema WHERE DB_COLUMN_PREFIXname='TagsMap';

# R_Tags_1.0
DROP TABLE DB_TABLE_PREFIXTags;

DELETE FROM DB_TABLE_PREFIXSchema WHERE DB_COLUMN_PREFIXname='Tags';

# TagItemMap
CREATE TABLE DB_TABLE_PREFIXTagItemMap(
 DB_COLUMN_PREFIXitemId INTEGER,
 DB_COLUMN_PREFIXtagId INTEGER
);

ALTER TABLE DB_TABLE_PREFIXTagItemMap ADD PRIMARY KEY (DB_COLUMN_PREFIXitemId, DB_COLUMN_PREFIXtagId);

CREATE INDEX DB_TABLE_PREFIXTagIt12_57276
   ON DB_TABLE_PREFIXTagItemMap(DB_COLUMN_PREFIXtagId);

INSERT INTO DB_TABLE_PREFIXSchema (
 DB_COLUMN_PREFIXname,
 DB_COLUMN_PREFIXmajor,
 DB_COLUMN_PREFIXminor
) VALUES('TagItemMap', 1, 0);

# TagMap
CREATE TABLE DB_TABLE_PREFIXTagMap(
 DB_COLUMN_PREFIXtagId INTEGER NOT NULL,
 DB_COLUMN_PREFIXtagName VARCHAR(128) NOT NULL
);

ALTER TABLE DB_TABLE_PREFIXTagMap ADD PRIMARY KEY (DB_COLUMN_PREFIXtagId);

CREATE UNIQUE INDEX DB_TABLE_PREFIXTagMade_13536  
 ON DB_TABLE_PREFIXTagMap(DB_COLUMN_PREFIXtagName);

INSERT INTO DB_TABLE_PREFIXSchema (
 DB_COLUMN_PREFIXname,
 DB_COLUMN_PREFIXmajor,
 DB_COLUMN_PREFIXminor
) VALUES('TagMap', 1, 0);

## mssql
# R_TagsMap_1.0
DROP TABLE DB_TABLE_PREFIXTagsMap;

DELETE FROM DB_TABLE_PREFIXSchema WHERE DB_COLUMN_PREFIXname='TagsMap';

# R_Tags_1.0
DROP TABLE DB_TABLE_PREFIXTags;

DELETE FROM DB_TABLE_PREFIXSchema WHERE DB_COLUMN_PREFIXname='Tags';

# TagItemMap
CREATE TABLE DB_TABLE_PREFIXTagItemMap(
 DB_COLUMN_PREFIXitemId INT NULL,
 DB_COLUMN_PREFIXtagId INT NULL
);

ALTER TABLE DB_TABLE_PREFIXTagItemMap ADD PRIMARY KEY (DB_COLUMN_PREFIXitemId, DB_COLUMN_PREFIXtagId);

CREATE INDEX DB_TABLE_PREFIXTagItemMap_57276 ON DB_TABLE_PREFIXTagItemMap(DB_COLUMN_PREFIXtagId);

INSERT INTO DB_TABLE_PREFIXSchema (
 DB_COLUMN_PREFIXname,
 DB_COLUMN_PREFIXmajor,
 DB_COLUMN_PREFIXminor
) VALUES('TagItemMap', 1, 0);

# TagMap
CREATE TABLE DB_TABLE_PREFIXTagMap(
 DB_COLUMN_PREFIXtagId INT NOT NULL,
 DB_COLUMN_PREFIXtagName NVARCHAR(128) NOT NULL
);

ALTER TABLE DB_TABLE_PREFIXTagMap ADD PRIMARY KEY (DB_COLUMN_PREFIXtagId);

CREATE UNIQUE INDEX DB_TABLE_PREFIXTagMap_13536 ON DB_TABLE_PREFIXTagMap(DB_COLUMN_PREFIXtagName);

INSERT INTO DB_TABLE_PREFIXSchema (
 DB_COLUMN_PREFIXname,
 DB_COLUMN_PREFIXmajor,
 DB_COLUMN_PREFIXminor
) VALUES('TagMap', 1, 0);
