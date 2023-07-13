## Temperature-Humidity-monitoring

### Problem Statment
Maintaining appropriate temperature and humidity levels in indoor spaces is crucial for the well-being and productivity of occupants. The ideal range for temperature is 20ºC to 25ºC, and for humidity, it is 30% to 50% relative humidity. If the temperature is too high, it can lead to health risks like heat exhaustion, heat stroke, and decreased productivity. On the other hand, too cold can cause health problems such as high blood pressure, asthma, and poor mental health. A dry indoor environment can also cause skin problems, nosebleeds, and sore throats, while excessive humidity can lead to dampness and mould growth.

Climate change has made it even more important for landlords and business owners to monitor and regulate indoor temperature and humidity levels. Electronic equipment, building construction, and certain industrial practices can affect the indoor environment. However, most buildings do not have a comprehensive monitoring system for temperature and humidity, and readings are usually limited to a single heating zone. By implementing an IoT system that tracks temperature and humidity and displays the data on a cloud-based dashboard, building owners can identify and prevent dangerous indoor environments that can cause health issues such as heat illnesses, cognitive impairment, mould growth, and mental health problems. Maintaining temperature and humidity levels within the safe ranges of 25ºC and 50% moisture and 20ºC and 30% moisture, respectively, is essential.

### System Architecture 


### Sensors 
##### ESP 32
![image](https://github.com/moha-55/Final-documentation/assets/121754960/c1ffd2fc-26a9-42b4-86ea-90033ba6d36c)


##### Temperature and Humidity Sensor (DHT22)
![image](https://github.com/moha-55/Final-documentation/assets/121754960/84d4b956-7d9d-4935-a158-80d6f10e2428)

OverviewOverview
![image](https://github.com/moha-55/Final-documentation/assets/121754960/a2eef10d-f1eb-4983-979c-60e224734a38)

### Dashboard
InfluxDB
![image](https://github.com/moha-55/Final-documentation/assets/121754960/3ae6133f-dc16-4905-8a30-6a451003162f)

Garfana
![image](https://github.com/moha-55/Final-documentation/assets/121754960/e2163ef2-d9ea-446d-929e-b13cb1f3757d)

### Database
![image](https://github.com/moha-55/Final-documentation/assets/121754960/b86c79a9-4ab6-4dd7-9c3a-2317477e8801)
