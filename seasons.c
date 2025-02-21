#include <stdio.h>

typedef struct
{
    int yy; // год
    char mm; // месяц
    char dd; // день
}Data;

typedef struct
{
    int yy; // год
    char season; // время года (зима - 0, весна - 1, лето - 2, осень - 3)
    int day; // день от начала текущего времени года
}Season;

Data getData(){
    Data a;
    scanf("%d-%d-%d", &a.yy, &a.mm, &a.dd);
    return a;
}

void printData(Data a){
    printf("%04d-%02d-%02d\n", a.yy, a.mm, a.dd);
}

// конвертирует дату в формат Season и возвращает это значение
// зима с 1 декабря по конец февраля, весна - с 1 марта по 31 мая, лето - с 1 июня по 31 августа,
// осень - с 1 сентября по 30 ноября
Season convToSeas(Data b){
    Season a;
    a.yy = b.yy;
    switch (b.mm){
        case (char)12 : //декабрь
            a.season = 0;
            a.day = b.dd;
            break;
        case 1 : //январь
            a.season = 0;
            a.day = b.dd + 31;
            break;
        case 2 : //февраль
            a.season = 0;
            a.day = b.dd + 62;
            break;
        case 3: //март
            a.season = 1;
            a.day = b.dd; 
            break;
        case 4: //апрель
            a.season = 1;
            a.day = b.dd + 31;
            break;
        case 5: // май
            a.season = 1;
            a.day = b.dd + 61;
            break;
        case 6: // июнь
            a.season = 2;
            a.day = b.dd;
            break;
        case 7: //июль
            a.season = 2;
            a.day = b.dd + 30;
            break;
        case 8: //август
            a.season = 2;
            a.day = b.dd + 61;
            break;
        case 9: //сентябрь
            a.season = 3;
            a.day = b.dd;
            break;
        case 10: // октябрь
            a.season = 3;
            a.day = b.dd + 30;
            break;
        case 11: // ноябрь
            a.season = 3;
            a.day = b.dd + 61;
        default:
            printf("error");
    }
    return a;
}

//  печать времени года в формате: YYYY-SS-DD (SS - номер времени года,
// DD - день от начала времени года, завершая переносом строки
void printSeas(Season a){
    printf("%04d-%02d-%02d", a.yy, a.season, a.day);
}

int main()
{
    Data dat;
    Season seas;
    dat = getData();
    printData(dat);
    seas = convToSeas(dat);
    printSeas(seas);
    return 0;
}