# PA - PRAKTIKUM - IoT - UNMUL

Kelompok 4 Kelas B:
- 2109106051 - Reihan Al Sya'ban
- 2109106081 - Anhar Khoirun Najib
- 2109106104 - M. Rangga Yaqub Wijaya
- 2109106127 - Auzan Hawaari Fahrony 

# SISTEM MONITORING DAN KONTROL ALARM KEBAKARAN RUANGAN DENGAN SENSOR API DAN SENSOR GERAK (PIR)
## Deskripsi 
Sistem Monitoring dan Kontrol Alarm Kebakaran Ruangan dengan Sensor Api dan Sensor Gerak, merupakan suatu sistem yang dirancang untuk mendeteksi dan memberikan peringatan dini terhadap kebakaran dalam ruangan. Sistem ini menggunakan sensor api dan sensor gerak yang terhubung dengan jaringan Internet menggunakan broker MQTTX untuk memonitor kondisi ruangan secara real-time menggunakan aplikasi android yang dibuat menggunakan tools milik kodular.io. 
Sistem akan mendeteksi adanya keberadaan api dalam ruangan menggunakan sensor api dan segera memberikan informasi kepada pengguna aplikasi dan menyalakan alarm kebakaran sebagai peringatan terdeteksinya api dalam ruangan. Sistem juga dapat memberikan informasi mengenai keberadaan seseorang dalam ruangan tersebut melalui sensor gerak (PIR). Informasi tersebut akan sangat berguna untuk tim penyelamat agar mengetahui kondisi ruangan yang telah terjadi kebakaran.

## Pembagian Tugas per Individu
- Sya'ban = Pembuatan rangkaian dan source code node publisher
- Anhar = Pembuatan aplikasi android dengan kodular dan konfigurasi perangkat IoT dengan MQTT dan aplikasi android
- Rangga = Pembuatan rangkaian dan source code node subscriber
- Auzan = Pembuatan rangkaian dan source code node subscriber

## Komponen Yang Digunakan 
1. Node Publisher
   - NodeMCU x 1
   - Sensor Api 5 Channel x 1
   - Sensor Gerak (PIR) x 1
   - Kabel Jumper Male - Male x 2
   - Kabel Jumper Male – Female x 6
2. Node Subscriber
   - NodeMCU x 1
   - Piezo Buzzer x 1
   - LED x 1
   - Kabel Jumper Male – Male x 2
   - Resistor x 1

## Board Schematic
1. Node Publisher
   ![schematic publisher](https://github.com/Anhar12/pa-praktikum-iot-unmul-b4/assets/92861249/145c7a0a-fdf7-4a20-83e2-b90a24d4dbed)

3. Node Subscriber
   ![schematic subscriber](https://github.com/Anhar12/pa-praktikum-iot-unmul-b4/assets/92861249/4d606461-6c2c-48be-b359-37680b68d60b)
