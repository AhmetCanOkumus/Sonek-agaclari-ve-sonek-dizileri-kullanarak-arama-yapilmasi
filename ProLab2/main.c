#include <stdio.h>
#include <stdlib.h>


struct kayit
{
    int ogrNo;
    int dersKodu;
    int puan;
};
struct tut
{
    int ogrencinotut;
    int derskodtut;
    int puantut;
};
void indexDosyasiOlustur()
{

    FILE *ptr=fopen("index.txt","a");

    if(ptr==NULL)
    {

        printf("Dosya olusturulamadi");
    }
    else
    {

        printf(" Index dosyasi olusturuldu") ;
    }
    fclose(ptr);

    printf("\n");

}
void indeksDosyasiniSil()
{

    remove("index.txt");
    printf("Indeks Dosyasi Silindi");
}
void kayitEkle()
{

    FILE *aptr=fopen("veri.bin","ab");

    struct kayit ogrenci[100];

    struct kayit *ptut=ogrenci;

    ptut=malloc(100*(sizeof(int)));

    int i;

    printf("Ogrenci numarasi giriniz:");
    scanf("%d",&ptut->ogrNo);
    printf("Ders kodu giriniz:");
    scanf("%d",&ptut->dersKodu);
    printf("Puani giriniz:");
    scanf("%d",&ptut->puan);

    if(ptut->ogrNo>0 || ptut->dersKodu>0 || ptut->puan>0){

    fprintf(aptr,"%d ",ptut->ogrNo);
    fprintf(aptr,"%d ",ptut->dersKodu);
    fprintf(aptr,"%d\n",ptut->puan);

    }
    fclose(aptr);

//----------------------------------

    free(ptut);
}
void kayitBul(struct tut ogrenci[],int elms,struct tut ogrenci2[],int elms2)
{

    int anahtar;
    int temp=0;

    printf("Aranacak ogrenci numarasini giriniz:");
    scanf("%d",&anahtar);

    int enk=0;
    int enb=elms-1;
    int orta=0;

    int ind=0;

    int k=0;

    while(enk<=enb)
    {
        orta=(enk+enb)/2;
        if(ogrenci[orta].ogrencinotut==anahtar)
        {

            while(orta-k>=0)
            {

                if(ogrenci[orta-k].ogrencinotut==anahtar)
                {

                    k++;
                }
                else
                {
                    ind=orta-k;
                    temp=1;
                    break;

                }
            }
            if(temp==1)
            {

                ind++;
                printf("Index dosyasinda ogrenci numarasina ait ilk kayit:\n");
                printf("%d\t",ogrenci[ind].ogrencinotut);
                printf("%d\t",ogrenci[ind].derskodtut);
                printf("%d\n",ogrenci[ind].puantut);

                break;
            }
        }
        if(ogrenci[orta].ogrencinotut>anahtar)
        {
            enb=orta-1;
        }
        if(ogrenci[orta].ogrencinotut<anahtar)
        {
            enk=orta+1;
        }

    }

    printf("\n");
    printf("\n");
        if(temp==1){
      printf("Index dosyasinda ogrenci numarasina ait diger kayitlar:\n");

    int j;
    for(j=ind+1; j<elms; j++)
    {

        if(ogrenci[j].ogrencinotut==anahtar)
        {

            printf("%d\t",ogrenci[j].ogrencinotut);
            printf("%d\t",ogrenci[j].derskodtut);
            printf("%d\n",ogrenci[j].puantut);

        }
    }
        }
        else{
            printf("Girilen ogrenci numarasina ait kayit Index dosyasinda bulunmamaktadir:\n");
        }

    int m;

    for(m=0;m<elms2; m++)
    {

        if(ogrenci2[m].ogrencinotut==anahtar)
        {
            printf("\nVeri dosyasinda ogrenci numarasina ait ilk kayit:\n\n");

            printf("%d\t",ogrenci2[m].ogrencinotut);
            printf("%d\t",ogrenci2[m].derskodtut);
            printf("%d\n",ogrenci2[m].puantut);
            break;
        }
    }
    if(m==elms2){

    printf("Girilen ogrenci numarasina ait kayit Veri dosyasinda bulunmamaktadir:\n\n");
    }
    else{
   printf("Veri dosyasinda girilen ogrenci numarasina ait diger kayitlar:\n\n");

   int z;
   for(z=m+1;z<elms2;z++){

         if(ogrenci2[z].ogrencinotut==anahtar){
            printf("%d\t",ogrenci2[z].ogrencinotut);
            printf("%d\t",ogrenci2[z].derskodtut);
            printf("%d\n",ogrenci2[z].puantut);
         }
   }
    }
}
void kayitSil(struct tut ogrenci[], struct tut ogrenci2[], int elms){

    int anahtar,dersk,dersp;
    int i;

    printf("Silinecek Anahtari Girin: ");
    scanf("%d",&anahtar);
    printf("Anahtara Ait Ders Kodu Girin:  ");
    scanf("%d",&dersk);
    printf("Anahtara Ait Puani Girin: ");
    scanf("%d",&dersp);

    FILE *ptr;
    FILE *aptr;

    ptr= fopen("index.txt","r");
    aptr=fopen("veri.bin","rb");

    FILE  *xptr=fopen("yed.bin","wb");
    FILE *zptr=fopen("yed2.txt","w");

    for(i=0;i<=elms;i++){

        if(anahtar!=ogrenci[i].ogrencinotut || dersk!=ogrenci[i].derskodtut || dersp!=ogrenci[i].puantut){

            if(ogrenci[i].ogrencinotut>0 &&ogrenci[i].derskodtut>0 && ogrenci[i].puantut>0){
            fprintf(zptr,"%d ",ogrenci[i].ogrencinotut);
            fprintf(zptr,"%d ",ogrenci[i].derskodtut);
            fprintf(zptr,"%d\n",ogrenci[i].puantut);
            }
        }
    }

    fclose(ptr);
    fclose(zptr);

    remove("index.txt");
    rename("yed2.txt","index.txt");

    for(i=0;i<=elms;i++){

        if(anahtar!=ogrenci2[i].ogrencinotut || dersk!=ogrenci2[i].derskodtut || dersp!=ogrenci2[i].puantut){

            if(ogrenci2[i].ogrencinotut>0 && ogrenci2[i].derskodtut>0 && ogrenci2[i].puantut>0){
            fprintf(xptr,"%d ",ogrenci2[i].ogrencinotut);
            fprintf(xptr,"%d ",ogrenci2[i].derskodtut);
            fprintf(xptr,"%d\n",ogrenci2[i].puantut);
            }
        }
    }

    fclose(aptr);
    fclose(xptr);

    remove("veri.bin");
    rename("yed.bin","veri.bin");

}
void kayitGuncelle(struct tut ogrenci[],struct tut ogrenci2[],int elms){

    FILE *ptr;
    FILE *yptr;
    FILE *bptr;
    FILE *aptr;
    int i,no,puan,kod;


    yptr=fopen("yedek.txt","w");
    ptr= fopen("index.txt","r");

    bptr =fopen("yedek.bin","w");
    aptr= fopen("veri.bin","rb");

    printf("Degistirilecek Kayita Ait Ogrenci Numarasini Girin: ");
    scanf("%d",&no);

    printf("Degistirilecek Kayita Ait Ders Kodu Girin: ");
    scanf("%d",&kod);

     printf("Degistirmek Istediginiz Puani Girin: ");
     scanf("%d",&puan);



    for(i=0;i<elms;i++){

        if(ogrenci[i].ogrencinotut!=no || ogrenci[i].derskodtut!=kod){

            if(ogrenci[i].ogrencinotut>0 && ogrenci[i].derskodtut>0 && ogrenci[i].puantut>0){
            fprintf(yptr,"%d   ",ogrenci[i].ogrencinotut);
            fprintf(yptr,"%d   ",ogrenci[i].derskodtut);
            fprintf(yptr,"%d   \n",ogrenci[i].puantut);
            }


        }
        if(ogrenci[i].ogrencinotut==no && ogrenci[i].derskodtut==kod){
            if(ogrenci[i].ogrencinotut>0 && ogrenci[i].derskodtut>0 && ogrenci[i].puantut>0){
            fprintf(yptr,"%d   ",no);
            fprintf(yptr,"%d   ",kod);
            fprintf(yptr,"%d   \n",puan);
            }
        }


    }

    fclose(yptr);
    fclose(ptr);


    remove("index.txt");
    rename("yedek.txt","index.txt");

    for(i=0;i<elms;i++){

        if(ogrenci2[i].ogrencinotut!=no || ogrenci2[i].derskodtut!=kod){
            if(ogrenci2[i].ogrencinotut>0 && ogrenci2[i].derskodtut>0 && ogrenci2[i].puantut>0){
            fprintf(bptr,"%d ",ogrenci2[i].ogrencinotut);
            fprintf(bptr,"%d ",ogrenci2[i].derskodtut);
            fprintf(bptr,"%d\n",ogrenci2[i].puantut);
            }

        }
        if(ogrenci2[i].ogrencinotut==no && ogrenci2[i].derskodtut==kod){
            if(ogrenci2[i].ogrencinotut>0 && ogrenci[i].derskodtut>0 && ogrenci2[i].puantut>0){
            fprintf(bptr,"%d ",no);
            fprintf(bptr,"%d ",kod);
            fprintf(bptr,"%d\n",puan);
            }

        }


    }


    fclose(bptr);
    fclose(aptr);

    remove("veri.bin");
    rename("yedek.bin","veri.bin");

}
void veriDosyasiniGoster(struct tut ogrenci2[],int elms2){

    int i;

    printf("Veri dosyasindaki kayitlar:\n");

    for(i=0;i<elms2;i++){
    if(ogrenci2[i].ogrencinotut>0 && ogrenci2[i].derskodtut>0 && ogrenci2[i].puantut>0){


    printf("%d\t",ogrenci2[i].ogrencinotut);
    printf("%d\t",ogrenci2[i].derskodtut);
    printf("%d\n",ogrenci2[i].puantut);
      }
     }
    }
void indeksDosyasiniGoster(struct tut ogrenci[],int elms){

    int i;

    printf("Index dosyasindaki kayitlar:\n");

    for(i=0;i<elms;i++){
    if(ogrenci[i].ogrencinotut>0 && ogrenci[i].derskodtut>0 && ogrenci[i].puantut>0){


    printf("%d\t",ogrenci[i].ogrencinotut);
    printf("%d\t",ogrenci[i].derskodtut);
    printf("%d\n",ogrenci[i].puantut);
      }
     }
    }
int main()
{

    indexDosyasiOlustur();

    char x;
    printf("Kayit ekleme fonksiyonuna gitmek istiyorsaniz e harfini giriniz menuye gitmek icin baska bir tus giriniz: ");
    scanf("%c",&x);
    if(x=='e' || x=='E'){
          kayitEkle();
    }



    int sayac=0;
    int sayac2=0;
    int i;

    FILE *aptr;
    FILE *ptr;

    struct tut ogrenci[100];
    struct tut ogrenci2[100];

    aptr=fopen("veri.bin","rb");


    ptr=fopen("index.txt","w");

    while(!feof(aptr))
    {

        fscanf(aptr,"%d",&ogrenci[sayac].ogrencinotut);
        fscanf(aptr,"%d",&ogrenci[sayac].derskodtut);
        fscanf(aptr,"%d",&ogrenci[sayac].puantut);
        sayac++;
    }
    fclose(aptr);
    fopen("veri.bin","rb");
    while(!feof(aptr))
    {
        fscanf(aptr,"%d",&ogrenci2[sayac2].ogrencinotut);
        fscanf(aptr,"%d",&ogrenci2[sayac2].derskodtut);
        fscanf(aptr,"%d",&ogrenci2[sayac2].puantut);
        sayac2++;
    }
    for(int d=0; d<sayac; d++)
    {

        for(int b=1; b<sayac-d; b++)
        {

            if(ogrenci[b-1].ogrencinotut>ogrenci[b].ogrencinotut)
            {

                int temp=ogrenci[b].ogrencinotut;
                ogrenci[b].ogrencinotut=ogrenci[b-1].ogrencinotut;
                ogrenci[b-1].ogrencinotut=temp;

                temp=ogrenci[b].derskodtut;
                ogrenci[b].derskodtut=ogrenci[b-1].derskodtut;
                ogrenci[b-1].derskodtut=temp;

                temp=ogrenci[b].puantut;
                ogrenci[b].puantut=ogrenci[b-1].puantut;
                ogrenci[b-1].puantut=temp;
            }
        }
    }
    for(int c=0; c<sayac; c++)
    {

        if(ogrenci[c].ogrencinotut>0&&ogrenci[c].derskodtut>0&&ogrenci[c].puantut>0)
        {

            fprintf(ptr,"%d   ",ogrenci[c].ogrencinotut);
            fprintf(ptr,"%d   ",ogrenci[c].derskodtut);
            fprintf(ptr,"%d   \n",ogrenci[c].puantut);
        }
    }

    fclose(aptr);

    fclose(ptr);

    int elms=sayac;
    int elms2=sayac2;




    printf("1-> Kayit Bul\n");
    printf("2-> Kayit Silme\n");
    printf("3-> Kayit Guncelleme\n");
    printf("4-> Veri Dosyasini Gosterme\n");
    printf("5-> Indeks Dosyasini Gosterme\n");
    printf("6-> Indeks Dosyasini Silme\n");
    printf("7-> Cikis Yapma\n");


       int secim;

    printf("Lutfen Yapmak Istediginiz Islemi Seciniz: ");
    scanf("%d",&secim);


      switch(secim){

    case 1: kayitBul(ogrenci,elms,ogrenci2,elms2);
      break;

    case 2: kayitSil(ogrenci,ogrenci2,elms);
       break;

    case 3: kayitGuncelle(ogrenci,ogrenci2,elms);
      break;

    case 4: veriDosyasiniGoster(ogrenci2,elms2);
     break;

    case 5: indeksDosyasiniGoster(ogrenci,elms);

      break;
    case 6: indeksDosyasiniSil();
       break;
    case 7:

     printf("Menuden ciktiniz\n");

       break;

    default:
        printf("Girilen sayi degeri gecersiz\n");
        break;
      }

   }
