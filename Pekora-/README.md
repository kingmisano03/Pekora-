#  Recomote control Boat
ระบบบังคับเรือโดยการ ใช้จอยบังคับ สำหรับบังคับตัวเรือให้แล่นไปข้างหน้า โดยสามารถบังคับเดินหน้า ซ้าย-ขวา ใช้สำหรับการละเล่น
## รายละเอียดโปรเจค
 ### Preception Module
 - infared remote controller
 - water level sensor
 ### Behavior 
 1. รับข้อมูลจากตัวรีโมต 
 2. ส่งข้อมูลไปยัง relay และส่งไปยัง motor
 3. ในกรณีนํ้าเข้าเรือจะเข้าตัว water sensor
 ### Manipulation Module
 - relay 
 - Buzzer 
 - Motor
 ### โครงสร้างพื้นฐาน
 ![diagram picture][diagram]
 
 [diagram]: https://github.com/kingmisano03/Pekora-/blob/master/diagram.jpg "Diagram"

### ระบบการทำงาน
![flowchart picture][flowchart]

[flowchart]: https://github.com/kingmisano03/Pekora-/blob/master/flowchart.PNG "flowchart"
