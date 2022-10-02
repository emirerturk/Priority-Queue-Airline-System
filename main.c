#include <stdio.h>
#include <stdlib.h>
FILE *input,*output;
int elemansayisi=0;
struct erte
{
    int id;
    int ertemiktar;
};
struct erte erteD[30];
struct Ucak
{
    int oncelik_id;
    int ucak_id;
    int talep_edilen_inis_saati;
    int indigiSaat;

};

struct Ucak queue[30];
struct Ucak dizi[28];
struct Ucak geciciD[28];
int kapasite=30;

int on=0;
int arka=0;

int DoluMu()
{
    if(elemansayisi<kapasite)
        return 1;
    else
        return 0;

}
void iziniste(int k)
{


    if(arka==0)
    {
        if(DoluMu())
        {
             int y;
                for(y=0; y<30; y++)
                {
                    if(dizi[k].ucak_id==erteD[y].id)
                    {
                        break;
                    }
                }

                if(erteD[y].ertemiktar>2)
                {
                    printf("Izniniz iptal edildi.Baska Havalimanina yonlendiriliyorsunuz.\n");


                }
                else
                {


            queue[arka].oncelik_id=dizi[k].oncelik_id;
            queue[arka].ucak_id=dizi[k].ucak_id;
            queue[arka].talep_edilen_inis_saati=dizi[k].talep_edilen_inis_saati;
            queue[arka].indigiSaat=queue[arka].talep_edilen_inis_saati;
fprintf(output," %d %d %d %d %d %d\n",queue[arka].oncelik_id,queue[arka].ucak_id,queue[arka].talep_edilen_inis_saati,queue[arka].indigiSaat,queue[arka].indigiSaat
               -queue[arka].talep_edilen_inis_saati,queue[arka].indigiSaat+1);
            geciciD[arka].oncelik_id=dizi[k].oncelik_id;
            geciciD[arka].ucak_id=dizi[k].ucak_id;
            geciciD[arka].talep_edilen_inis_saati=dizi[k].talep_edilen_inis_saati;
            geciciD[arka].indigiSaat=queue[arka].talep_edilen_inis_saati;
            printf("%d oncelikli %d idli ucaga %d saatinde inis izni verildi.\n",
                   geciciD[arka].oncelik_id,geciciD[arka].ucak_id,geciciD[arka].indigiSaat);
                    printf("%d oncelikli %d idli ucaga %d saatinde kalkis izni verildi.\n",
               geciciD[arka].oncelik_id,geciciD[arka].ucak_id,geciciD[arka].indigiSaat+1);
            arka++;
            elemansayisi++;
}

        }
    }
    else
    {
        for(int i=on; i<=arka; i++)

        {
             int y;
                for(y=0; y<30; y++)
                {
                    if(dizi[k].ucak_id==erteD[y].id)
                    {
                        break;
                    }
                }

                if(erteD[y].ertemiktar>2)
                {
                    printf("Izniniz iptal edildi.Baska Havalimanina yonlendiriliyorsunuz.\n");
 break;
                }
                else
                {


            if(dizi[k].indigiSaat==geciciD[i].indigiSaat)
            {
                printf("%d %d %d sirali ucak %d %d %d li ucakla ayni saatte inmek istiyor\n",
                       dizi[k].oncelik_id,dizi[k].ucak_id,dizi[k].indigiSaat,
                       geciciD[i].oncelik_id,geciciD[i].ucak_id,geciciD[i].indigiSaat);
                inis_pisti_kullanim_sirasi(k,i);


                break;
            }

            else if(dizi[k].talep_edilen_inis_saati>geciciD[i+1].indigiSaat && i==arka)
            {

                int y;
                for(y=0; y<30; y++)
                {
                    if(dizi[k].ucak_id==erteD[y].id)
                    {
                        break;
                    }
                }

                if(erteD[y].ertemiktar>2)
                {
                    printf("Izniniz iptal edildi.Baska Havalimanina yonlendiriliyorsunuz.\n");
 break;
                }
                else
                {

                    geciciD[arka].oncelik_id=dizi[k].oncelik_id;
                    geciciD[arka].ucak_id=dizi[k].ucak_id;
                    geciciD[arka].talep_edilen_inis_saati=dizi[k].talep_edilen_inis_saati;
                    geciciD[arka].indigiSaat=dizi[k].indigiSaat;
                    printf("%d oncelikli %d idli ucaga %d saatinde inis izni verildi.\n",
                           geciciD[arka].oncelik_id,geciciD[arka].ucak_id,geciciD[arka].indigiSaat%24);
                           printf("%d oncelikli %d idli ucaga %d saatinde kalkis izni verildi.\n",
                           geciciD[arka].oncelik_id,geciciD[arka].ucak_id,(geciciD[arka].indigiSaat+1)%24);
                    queue[arka].oncelik_id=dizi[k].oncelik_id;
                    queue[arka].ucak_id=dizi[k].ucak_id;
                    queue[arka].talep_edilen_inis_saati=dizi[k].talep_edilen_inis_saati;
                    queue[arka].indigiSaat=dizi[k].indigiSaat;
                     fprintf(output," %d %d %d %d %d %d\n",queue[arka].oncelik_id,queue[arka].ucak_id,(queue[arka].talep_edilen_inis_saati)%24,queue[arka].indigiSaat%24,queue[arka].indigiSaat
               -queue[arka].talep_edilen_inis_saati,(queue[arka].indigiSaat+1)%24);
                    arka++;
                    elemansayisi++;
                    break;

                }

            }
        }
        }


    }

}
void inis_pisti_kullanim_sirasi(int k,int i)
{
    if(dizi[k].oncelik_id==geciciD[i].oncelik_id)
    {

        if(dizi[k].ucak_id>geciciD[i].ucak_id)
        {
            printf("%d oncelikli %d idli ucak %d saatinde ayni oncelikte baska bir ucak daha once izin istedigi icin erteleniyor.\n",
                   dizi[k].oncelik_id,dizi[k].ucak_id,dizi[k].indigiSaat);
            int y;
            for(y=0; y<30; y++)
            {
                if(dizi[k].ucak_id==erteD[y].id)
                {
                    erteD[y].ertemiktar=erteD[y].ertemiktar+1;
                }
            }
            dizi[k].indigiSaat=dizi[k].indigiSaat+1;


            if(erteD[y].ertemiktar>2)
            {
                printf("Izniniz iptal edildi.Baska Havalimanina yonlendiriliyorsunuz.\n");

            }
            else
            {

                printf("%d oncelikli %d idli ucak %d saatinde inis talep ediyor.\n",dizi[k].oncelik_id,dizi[k].ucak_id,dizi[k].indigiSaat);
                iziniste(k);
            }


        }
        else
        {

            printf("Ayni oncelikli baska bir ucak  daha once inis izni istedigi icin %d %d %d ucagi erteleniyor\n",
                   dizi[k].oncelik_id,dizi[k].ucak_id,dizi[k].indigiSaat);
            printf("Ucak erteleniyor %d %d %d----->%d\n",dizi[k].oncelik_id,dizi[k].ucak_id,dizi[k].indigiSaat,dizi[k].indigiSaat+1);
            int y;
            for(y=0; y<30; y++)
            {
                if(dizi[k].ucak_id==erteD[y].id)
                {
                    erteD[y].ertemiktar=erteD[y].ertemiktar+1;
                }
            }

            dizi[k].indigiSaat=dizi[k].indigiSaat+1;

            if(erteD[y].ertemiktar>2)
            {
                printf("Izniniz iptal edildi.Baska Havalimanina yonlendiriliyorsunuz.\n");

            }
            else
            {
                printf("%d oncelikli %d idli ucak %d saatinde inis talep ediyor.\n",dizi[k].oncelik_id,dizi[k].ucak_id,dizi[k].indigiSaat);
                iziniste(k);

            }

        }
    }

    else if(dizi[k].oncelik_id>geciciD[i].oncelik_id)
    {

        printf("Ucak erteleniyor %d %d %d----->%d\n",dizi[k].oncelik_id,dizi[k].ucak_id,dizi[k].indigiSaat,dizi[k].indigiSaat+1);
        int y;
        for(y=0; y<30; y++)
        {
            if(dizi[k].ucak_id==erteD[y].id)
            {
                erteD[y].ertemiktar=erteD[y].ertemiktar+1;
            }
        }

        dizi[k].indigiSaat=dizi[k].indigiSaat+1;
        ;
        if(erteD[y].ertemiktar>2)
        {
            printf("Izniniz iptal edildi.Baska Havalimanina yonlendiriliyorsunuz.\n");

        }
        else
        {
            printf("%d oncelikli %d idli ucak %d saatinde inis talep ediyor.\n",dizi[k].oncelik_id,dizi[k].ucak_id,dizi[k].indigiSaat);
            iziniste(k);

        }



    }

    else if(dizi[k].oncelik_id<geciciD[i].oncelik_id)
    {
        printf("%d %d %d ucagi %d %d %d ucagindan daha oncelikli olarak piste inis izni veriliyor \n",dizi[k].oncelik_id,dizi[k].ucak_id,dizi[k].indigiSaat,
               geciciD[i].oncelik_id,geciciD[i].ucak_id,geciciD[i].indigiSaat);
               printf("%d oncelikli %d idli ucaga %d saatinde kalkis izni veriliyor\n",dizi[k].oncelik_id,dizi[k].ucak_id,dizi[k].indigiSaat,
               geciciD[i].oncelik_id,geciciD[i].ucak_id,geciciD[i].indigiSaat+1);

        queue[i].oncelik_id=dizi[k].oncelik_id;
        queue[i].ucak_id=dizi[k].ucak_id;
        queue[i].talep_edilen_inis_saati=dizi[k].talep_edilen_inis_saati;
        queue[i].indigiSaat=dizi[k].indigiSaat;
 fprintf(output," %d %d %d %d %d %d\n",queue[i].oncelik_id,queue[i].ucak_id,queue[i].talep_edilen_inis_saati,queue[i].indigiSaat,queue[i].indigiSaat
               -queue[i].talep_edilen_inis_saati,queue[i].indigiSaat+1);

        printf("%d oncelikli %d idli ucaga %d saatinde inis izni verildi.\n",
               dizi[k].oncelik_id,dizi[k].ucak_id,dizi[k].indigiSaat);
                printf("%d oncelikli %d idli ucaga %d saatinde kalkis izni verildi.\n",
               dizi[k].oncelik_id,dizi[k].ucak_id,dizi[k].indigiSaat+1);

        printf("%d %d %d ucak erteleniyor\n",geciciD[i].oncelik_id,geciciD[i].ucak_id,geciciD[i].indigiSaat);
        int y;
        for(y=0; y<30; y++)
        {
            if(geciciD[i].ucak_id==erteD[y].id)
            {
                erteD[y].ertemiktar=erteD[y].ertemiktar+1;
            }
        }
        geciciD[i].indigiSaat=geciciD[i].indigiSaat+1;

        printf("%d oncelikli %d idli ucak %d saatinde inis talep ediyor.\n",geciciD[i].oncelik_id,geciciD[i].ucak_id,geciciD[i].indigiSaat);

        if(erteD[y].ertemiktar>2)
        {
            printf("Izniniz iptal edildi.Baska Havalimanina yonlendiriliyorsunuz.\n");

        }
        else
        {
            printf("%d oncelikli %d idli ucak %d saatinde inis talep ediyor.\n",dizi[k].oncelik_id,dizi[k].ucak_id,dizi[k].indigiSaat);

            iziniste(i);
        }


        geciciD[i].oncelik_id=dizi[k].oncelik_id;
        geciciD[i].ucak_id=dizi[k].ucak_id;
        geciciD[i].talep_edilen_inis_saati=dizi[k].talep_edilen_inis_saati;
        geciciD[i].indigiSaat=dizi[k].indigiSaat;
    }

}

void Liste()
{
    printf("\n*****************\n");
    printf("oncelik_id, ucak_id, talep_edilen_inis_saati, inis_saati, gecikme_suresi, kalkis_saati\n");
    for(int i=on; i<arka; i++)
    {

        printf(" %d %d %d %d %d %d\n",queue[i].oncelik_id,queue[i].ucak_id,(queue[i].talep_edilen_inis_saati)%24,queue[i].indigiSaat%24,queue[i].indigiSaat
               -queue[i].talep_edilen_inis_saati,(queue[i].indigiSaat+1)%24);
    }

}


int main()
{
    int x;
    input=fopen("input.txt","r");
     output=fopen("output.txt","a+");
    while(!feof(input))
    {
        fscanf(input,"%d %d %d\n",&dizi[x].oncelik_id,&dizi[x].ucak_id,&dizi[x].talep_edilen_inis_saati);
        x++;
    }
    fclose(input);

    int i,j,temp,temp2,temp3;

    for(i=0; i<28; i++)
    {
        for(j=0; j<i+1; j++)
        {
            if(dizi[j].talep_edilen_inis_saati>dizi[i].talep_edilen_inis_saati)
            {
                temp=dizi[i].oncelik_id;
                dizi[i].oncelik_id=dizi[j].oncelik_id;
                dizi[j].oncelik_id=temp;

                temp2=dizi[i].ucak_id;
                dizi[i].ucak_id=dizi[j].ucak_id;
                dizi[j].ucak_id=temp2;

                temp3=dizi[i].talep_edilen_inis_saati;
                dizi[i].talep_edilen_inis_saati=dizi[j].talep_edilen_inis_saati;
                dizi[j].talep_edilen_inis_saati=temp3;
            }
        }
    }

    for(i=0; i<28; i++)
    {
        dizi[i].indigiSaat=dizi[i].talep_edilen_inis_saati;
        erteD[i].id=dizi[i].ucak_id;
        printf("%d oncelikli %d idli ucak %d saatinde inis talep ediyor.\n",dizi[i].oncelik_id,dizi[i].ucak_id,dizi[i].talep_edilen_inis_saati%24);
        iziniste(i);
        printf("\n");
        Liste();
    }

fclose(output);


    return 0;
}
