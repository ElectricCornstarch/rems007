from sqlalchemy import create_engine, Column, Boolean, Integer, Float, TIMESTAMP
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import sessionmaker

Base = declarative_base()

class Sensor(Base):
    __tablename__ = 'Sensors'
    
    time = Column("time", TIMESTAMP, primary_key=True, nullable=False)
    temperature_DHT22 = Column("temperature_DHT22", Float)
    temperature_DS18B20 = Column("temperature_DS18B20", Float)
    humidity_DHT22 = Column("humidity_DHT22", Float)
    motion = Column("motion", Boolean)
    smoke = Column("smoke", Boolean)
    waterLeak = Column("waterLeak", Boolean) # Don't Know what Datatype this should be
    vibration = Column("vibration", Boolean) # Don't Know what Datatype this should be
    
    def __init__(self, time, temperature_DHT22, temperature_DS18B20, humidity_DHT22, motion, smoke, waterLeak, vibration):
        self.time = time
        self.temperature_DHT22 = temperature_DHT22
        self.temperature_DS18B20 = temperature_DS18B20
        self.humidity_DHT22 = humidity_DHT22
        self.motion = motion
        self.smoke = smoke
        self.waterLeak = waterLeak
        self.vibration = vibration
        
    def __repr__(self):
        return f'time={self.time}, temperature_DHT22={self.temperature_DHT22}, temperature_DS18B20={self.temperature_DS18B20} humidity_DHT22={self.humidity_DHT22}, motion={self.motion}, smoke={self.smoke}, waterLeak={self.waterLeak}, vibration={self.vibration}'
    

def initDB():
    engine = create_engine("sqlite:///HGV_Sensor.db", echo=True)
    Base.metadata.create_all(bind=engine)
    Session = sessionmaker(bind=engine)
    return Session()

def addReading(session, time, temperature_DHT22, temperature_DS18B20, humidity_DHT22, motion, smoke, waterLeak, Vibration):
    newReading = Sensor(time, temperature_DHT22, temperature_DS18B20, humidity_DHT22, motion, smoke, waterLeak, Vibration)
    session.add(newReading)
    session.commit()
# Adding Data into the Database Can be remove later

# from datetime import datetime

# session = initDB()

# addReading(session,datetime.now(), 25.1, 25.1, 12.64, 0, 0, 0, 1 )