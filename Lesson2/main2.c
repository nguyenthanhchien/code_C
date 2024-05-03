#include<stdio.h>
#include<stdarg.h>

typedef enum{
    TEMPERATURE_TENSOR,
    PRESSURE_SENSOR
}SensorType;

void processSensorData(SensorType type,...)
{
    va_list args;
    va_start(args,type);

    switch (type)
    {
    case TEMPERATURE_TENSOR:
        {
            int numArgs = va_arg(args,int);
            int sensorID = va_arg(args,int);
            float temperature = va_arg(args,double);
            printf("Temperature Sensor ID : %d,Reading:%.2f degrees\n",sensorID,temperature);
            if(numArgs>2){
                char* additionalInfo = va_arg(args,char*);
                printf("Additional Info:%s\n",additionalInfo);
            }
        }
        break;
    case PRESSURE_SENSOR:
        {
            int numArgs = va_arg(args,int);
            int sensorID = va_arg(args,int);
            float pressure = va_arg(args,double);
            printf("Pressure Sensor ID : %d,Reading:%.2f degrees\n",sensorID,pressure);
            if(numArgs>2){
                char* unit = va_arg(args,char*);
                printf("Unit:%s\n",unit);
            }
        }
        break;
    
    default:
        break;
    }
    va_end(args);
}
int main()
{
    processSensorData(TEMPERATURE_TENSOR,5,1,35.00,"HI");
    processSensorData(PRESSURE_SENSOR,5,1,34.00,"HI");
    return 0;
}