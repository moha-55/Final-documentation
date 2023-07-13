import serial
import time
import influxdb_client
from influxdb_client import InfluxDBClient, Point, WritePrecision
from influxdb_client.client.write_api import SYNCHRONOUS
from serial import Serial

# Set up the serial line
ser = serial.Serial('COM3', 9600)  # Change 'COM3' to the appropriate COM port

token = "ffwSrgqUcyZV_OJDZKJ-lsk7kmFYbz57rwsg9RBC2akACT7XME5vQC_IfmaE_bvoTm7vONjFh0p22vg0gQ9qZw=="
org = "UTM University"
url = "http://192.168.1.10:8086"
bucket = "DHT1"

client = InfluxDBClient(url=url, token=token, org=org)
write_api = client.write_api(write_options=SYNCHRONOUS)

while True:
    try:
        b = ser.readline()         # Read a line from the serial port
        string_n = b.decode()  # Decode byte string into Unicode  
        string = string_n.rstrip() # Remove \n and \r

        print(f"Output from USB port: {string}")  # Print the output

        # Assuming the string format is "XX.YY,ZZ.WW" (humidity,temperature)
        parts = string.split(",")
        humidity_str = parts[0]
        temp_str = parts[1]

        humidity = float(humidity_str)
        temperature = float(temp_str)

        point = Point("DHT22_data") \
            .tag("location", "office") \
            .field("humidity", humidity) \
            .field("temperature", temperature) \
            .time(time.time_ns(), WritePrecision.NS)
            
        write_api.write(bucket=bucket, org=org, record=point)
        time.sleep(1)  # Separate points by 1 second
    except IndexError:
        print(f"Could not parse line: {string}")
    except Exception as e:
        print(f"Error: {e}")

ser.close()
