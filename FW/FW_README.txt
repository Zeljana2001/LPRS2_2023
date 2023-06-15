soilMoisture/soilMoisture.ino

-kod za senzor vlažnosti
-koristeći taj kod smo provjeravali da li i kako radi senzor vlažnosti
-pomoću bluetooth senzora smo slali informacije o vlažnosti na Bluetooth Terminal koji smo instalirali na svom telefonu

wateringAlgo/wateringAlgo.ino

-kod za pokretanje aktuatora za zalivanje biljke
-pomoću tog koda smo pokretali motor unutar pumpe koja povlači vodu iz boce od 5l i tako počinje zalivanje biljke


moistureApp/moistureApp.ino

-prvobitna konzolna aplikacija koja na Linux terminal šalje informacije o vlažnosti zemljišta koje dobija od senzora
-za njenu izradu je korišten kod iz soilMoisture/soilMoisture.ino
-ne koristi Bluetooth već preko serijskog priključka Arduina šalje infromacije na Linux Terminal


moistureAndWateringApp/moistureAndWteringApp.ino

-proširena konzolna aplikacija logikom za zalivanje biljke
-za njenu izradu su kombinovani moistureApp.ino i kod iz wateringAlgo/wateringAlgo.ino
-finalno rješenje za projekat Self sustaning plant
-takođe preko serijskog priključka Arduina šalje infromacije na Linux Terminal
-pokreće se preko komande screen kojoj proslijeđujemo odgovarajući serijski priključak, u našem slučaju to je /dev/ttyUSB0 (objašnjeno u LPRS2_2023/Uputstvo.txt)
