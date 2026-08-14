Donanım bağlantısı (BMP280 ile aynı hatta bile kullanabilirsiniz):

MPU6050 Pini	Blue Pill Pini
VCC	3.3V
GND	GND
SCL	PB6
SDA	PB7
AD0	GND → adres 0x68 (kodun varsayılanı) veya VCC → 0x69

Gerçek hayatta dikkat edilecekler (BMP280'dekiyle aynı mantık):

Pull-up dirençleri — çoğu MPU6050 breakout kartında (GY-521 gibi) zaten kartın üzerinde var, ama kontrol edin.
Burst okuma bu sürücüde aktif bırakıldı (14 byte'ı tek seferde okuyor) çünkü gerçek donanımda sorunsuz çalışır ve daha hızlıdır. PICSimLab'de test ederken hata alırsanız, MPU6050_ReadRegs içindeki tek HAL_I2C_Mem_Read çağrısını, BMP280'de yaptığımız gibi bir for döngüsüyle byte-byte okumaya çevirin — kod içine bunun nasıl yapılacağına dair bir yorum satırı da bıraktım.
DLPF (dijital filtre) ayarı 0x03 (~44Hz) olarak seçildi — titreşimli/gürültülü ortamlarda (drone, robot vb.) iyi bir varsayılan; çok hızlı hareket yakalamak isterseniz MPU6050_REG_CONFIG değerini düşürüp bant genişliğini artırabilirsiniz.
Kalibrasyon yok — gerçek projede ivmeölçer/jiroskop genelde küçük bir ofset (bias) taşır; hassas uygulamalarda (IMU, denge robotu vb.) açılışta birkaç yüz örnek alıp ortalamasını ofset olarak çıkarmanız önerilir. İsterseniz bunu da ekleyebilirim.

İki sensörü aynı I2C1 hattında (aynı SCL/SDA, farklı adresler: BMP280=0x76, MPU6050=0x68) birlikte de kullanabilirsiniz — hiçbir çakışma olmaz.
