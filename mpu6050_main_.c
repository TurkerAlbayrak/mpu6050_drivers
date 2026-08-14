/* ============================================================
 * Bu dosyanin ICERIGINI direkt derlemeye eklemeyin - CubeIDE main.c'yi
 * kendisi uretir. Asagidaki bloklari, main.c'deki ayni etiketli
 * "/* USER CODE BEGIN ... * /" - "/* USER CODE END ... * /" bloklarinin
 * ARASINA yapistirin (BMP280 ile ayni projede kullanacaksaniz,
 * mevcut BMP280 satirlarinin ALTINA/yanina ekleyin, silmeyin).
 * ============================================================ */


/* USER CODE BEGIN Includes */
#include "mpu6050.h"
/* USER CODE END Includes */


/* USER CODE BEGIN PV */
MPU6050_Data_t mpu6050_data;
/* USER CODE END PV */


/* USER CODE BEGIN 2 */
printf("\r\n--- MPU6050 Ivme/Jiroskop Sensoru Baslatiliyor ---\r\n");

HAL_StatusTypeDef mpuResult = MPU6050_Init(&hi2c1,
                                            MPU6050_ACCEL_RANGE_2G,
                                            MPU6050_GYRO_RANGE_250DPS);

printf("DEBUG: WhoAmI-status=%d WhoAmI=0x%02X (beklenen 0x68)\r\n",
       MPU6050_LastStatus, MPU6050_LastWhoAmI);

if (mpuResult == HAL_OK)
{
    printf("MPU6050 basariyla bulundu ve baslatildi.\r\n");
}
else
{
    printf("HATA: MPU6050 bulunamadi! I2C baglantilarini ve adresi kontrol edin.\r\n");
    Error_Handler();
}
/* USER CODE END 2 */


/* USER CODE BEGIN WHILE */
while (1)
{
    if (MPU6050_ReadAll(&mpu6050_data) == HAL_OK)
    {
        printf("Accel[g]: X=%.2f Y=%.2f Z=%.2f | Gyro[dps]: X=%.1f Y=%.1f Z=%.1f | Temp=%.1fC\r\n",
               mpu6050_data.accel_x_g, mpu6050_data.accel_y_g, mpu6050_data.accel_z_g,
               mpu6050_data.gyro_x_dps, mpu6050_data.gyro_y_dps, mpu6050_data.gyro_z_dps,
               mpu6050_data.temperature_C);
    }
    else
    {
        printf("MPU6050 okuma hatasi!\r\n");
    }

    HAL_Delay(200); /* MPU6050 icin BMP280'e gore daha sik okuma tipiktir (hareket algilama) */
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
}
/* USER CODE END 3 */
