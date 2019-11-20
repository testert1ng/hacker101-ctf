from sqlalchemy import create_engine 
from sqlalchemy.ext.declarative import declarative_base 
from sqlalchemy.orm import relationship, scoped_session, sessionmaker 
from sqlalchemy import Column, DateTime, ForeignKey, Boolean, Integer, Text, func, String 

engine = create_engine('sqlite:///level18.db', convert_unicode=True) 
db_session = scoped_session(sessionmaker(autocommit=False, autoflush=False, bind=engine)) 
Base = declarative_base() 
Base.query = db_session.query_property() 

class User(Base): 
	__tablename__ = 'users' 
	id = Column(Integer, primary_key=True) 
	username = Column(String(255)) 
	password = Column(String(255)) 
	bugs = relationship('Bug', primaryjoin='Bug.reporter_id==User.id') 

class Bug(Base): 
	__tablename__ = 'bugs' 
	id = Column(Integer, primary_key=True) 
	reporter_id = Column(Integer, ForeignKey('users.id')) 
	reporter = relationship(User, primaryjoin=reporter_id == User.id) 
	text = Column(Text(65536)) private = Column(Boolean()) 
	attachments = relationship('Attachment', primaryjoin='Attachment.bug_id==Bug.id') 

class Attachment(Base): 
	__tablename__ = 'attachments' 
	id = Column(Integer, primary_key=True) 
	bug_id = Column(Integer, ForeignKey('bugs.id')) 
	bug = relationship(Bug, primaryjoin=bug_id == Bug.id) 
	filename = Column(String(255))