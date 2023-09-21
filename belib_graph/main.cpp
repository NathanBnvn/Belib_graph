#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <gd.h>
#include <gdfonts.h>
#include <gdfontl.h>

using namespace std;
using json = nlohmann::json;

// Récupérer les données du fichier JSON
// Générer des graphiques à partir des données
//

int maxCount;
gdImagePtr chart;
int white, green, yellow, red, sunny_blue, grey, navy, pale_yellow, dark_purple, black, pink, olivine,
    cadet_grey, tyrian_purple, ash_gray, light_coral, plum, rose_ebony, sienna, cam_blue, brigde_blue;

void create_chart(gdImagePtr chart, int countByDepartement[20])
{}

int main()
{
    ifstream file("/home/ajc/Documents/belib.json");
    json data = json::parse(file);
    maxCount = end(data) - begin(data);
    int a = 0, b = 0,c = 0,d = 0,e = 0,f = 0,g = 0,h = 0,i = 0,j = 0,
        k = 0,l = 0,m = 0,n = 0,o = 0,p = 0,q = 0,r = 0,s = 0,t = 0;
    int legend_txt;
    int arrondissements[maxCount];
    for (int i = 0; i < maxCount; i++) {
        if(!data[i]["adresse_station"].empty()){
            //cout << data[i]["arrondissement"].get<std::string>() << "\n";
            string str3 = data[i]["adresse_station"].get<std::string>();

            str3.erase(str3.begin(), str3.end()-11);
            str3.erase(str3.begin()+5, str3.end());

            arrondissements[i] = stoi(str3);
        }

        //cout << addresses[i] << "\n";

        switch(arrondissements[i]){
        case 75001:
            a ++;
            break;

        case 75002:
            b ++;
            break;
        case 75003:
            c ++;
            break;
        case 75004:
            d ++;
            break;
        case 75005:
            e++;
            break;
        case 75006:
            f++;
            break;
        case 75007:
            g++;
            break;
        case 75008:
            h++;
            break;
        case 75009:
            i++;
            break;
        case 75010:
            j++;
            break;
        case 75011:
            k++;
            break;
        case 75012:
            l++;
            break;
        case 75013:
            m++;
            break;
        case 75014:
            n++;
            break;
        case 75015:
            o++;
            break;
        case 75016:
            p++;
            break;
        case 75017:
            q++;
            break;
        case 75018:
            r++;
            break;
        case 75019:
            s++;
            break;
        case 75020:
            t++;
            break;
        }

    }

    int countByArrondissements[20] = {a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t};

    FILE *png_file;
    chart = gdImageCreate(500, 500);

    white = gdImageColorAllocate(chart, 255, 255, 255);

    black = gdImageColorAllocate(chart, 0, 0, 0);
    yellow = gdImageColorAllocate(chart, 255, 178, 0);
    green = gdImageColorAllocate(chart, 110, 178, 0);
    grey = gdImageColorAllocate(chart, 130, 130, 130);
    navy = gdImageColorAllocate(chart, 0, 42, 111);
    pale_yellow = gdImageColorAllocate(chart, 255, 186, 73);
    sunny_blue = gdImageColorAllocate(chart, 32, 163, 158);
    red = gdImageColorAllocate(chart, 255, 0, 0);
    dark_purple = gdImageColorAllocate(chart, 35, 0, 30);
    pink = gdImageColorAllocate(chart, 239, 91, 91);

    cadet_grey = gdImageColorAllocate(chart, 164, 169, 173);
    tyrian_purple = gdImageColorAllocate(chart, 74, 0, 31);
    ash_gray = gdImageColorAllocate(chart, 167, 196, 194);
    light_coral = gdImageColorAllocate(chart, 246, 130, 140);
    plum = gdImageColorAllocate(chart, 160, 62, 153);
    rose_ebony = gdImageColorAllocate(chart, 89, 56, 55);
    sienna = gdImageColorAllocate(chart, 148, 41, 17);
    cam_blue = gdImageColorAllocate(chart, 148, 185, 175);
    brigde_blue = gdImageColorAllocate(chart, 144, 165, 131);
    olivine = gdImageColorAllocate(chart, 171, 181, 87);


    int colors[20] = {black, yellow, green, grey, navy, sunny_blue, red, pale_yellow, dark_purple, pink, cadet_grey,
                      tyrian_purple, ash_gray, light_coral, plum, rose_ebony, sienna, cam_blue, brigde_blue, olivine};


    gdImageSetAntiAliased(chart, gdTrueColorAlpha(255, 0, gdBlueMax, gdAlphaOpaque));

    int x = 0;
    int y;
    char tst[13];

    int text_y = 20;
    int text_x = 20;
    int color_legend_y_2 = 30;
    int color_legend_y = 25;

    for(int c = 0; c < 20; c++){
        if(countByArrondissements[c] > 0) {
            if(c > 0){
                x = x + y;
            }
            y = (((countByArrondissements[c]/ 19)) * 360) /100;
            gdImageFilledArc(chart, 250, 250, 250, 250, x, y, colors[c], gdPie);

        }else{
            cout << "arr" << c << " = 0 \n";
        }
        //= "10% - 20 Arr";
        snprintf(tst, 13, "%d%% - %d Arr.", (countByArrondissements[c]*100) / 1991, c+1);

        gdImageFilledRectangle(chart, 10, color_legend_y, 15, color_legend_y_2, colors[c]);
        gdImageString(chart, gdFontSmall, text_x, text_y, (unsigned char*)tst, black);
        text_y = text_y + 20;
        color_legend_y_2 = color_legend_y_2 + 20;
        color_legend_y = color_legend_y + 20;
    }


    // add system to change colors

    gdImageSetAntiAliased(chart, gdTrueColorAlpha(255, 0, gdBlueMax, gdAlphaOpaque));
    gdImageArc(chart, 250, 250, 250, 250, 0, 360, black);
    //x = y;

    png_file = fopen("test.png", "wb");

    gdImagePng(chart, png_file);
    fclose(png_file);

    gdImageDestroy(chart);

    //create_chart(chart, &countByDepartement[20]);
    //int * percentage = nullptr;


    return 0;
}

/*
void create_chart(gdImagePtr chart)
{

    FILE *png_file;

    white = gdImageColorAllocate(chart, 255, 255, 255);

    black = gdImageColorAllocate(chart, 0, 0, 0);
    yellow = gdImageColorAllocate(chart, 255, 178, 0);
    green = gdImageColorAllocate(chart, 110, 178, 0);
    grey = gdImageColorAllocate(chart, 130, 130, 130);
    navy = gdImageColorAllocate(chart, 0, 42, 111);
    red = gdImageColorAllocate(chart, 255, 0, 0);

    //gdImageFilledArc(chart, 250, 250, 250, 250, 0, 88, yellow, gdPie);
    //gdImageArc(chart, 250, 250, 250, 250, 0, 88, black);

    //gdImageFilledArc(chart, 250, 250, 250, 250, 88, 91, navy, gdPie);
    //gdImageFillToBorder(chart, 88, 250, 12, black);

    //gdImageFilledArc(chart, 250, 250, 250, 250, 91, 120, grey, gdPie);
    //gdImageArc(chart, 250, 250, 250, 250, 91, 120, black);

    //gdImageFilledArc(chart, 250, 250, 250, 250, 120, 180 , green, gdPie);
    //gdImageArc(chart, 250, 250, 250, 250, 120, 180, black);

    //gdImageFilledArc(chart, 250, 250, 250, 250, 180, 360, red, gdPie);
    //gdImageArc(chart, 250, 250, 250, 250, 180, 360, black);

    //gdImageLine(chart, 250, 250, 375, 250, black);
    //gdImageLine(chart, 250, 250, 250+4, 375, black);

    gdImageSetAntiAliased(chart, gdTrueColorAlpha(255, 0, gdBlueMax, gdAlphaOpaque));

    //gdImageString(chart, gdFontSmall, 250, 250, "blaise", black);
    //gdImageString(chart, gdFontSmall, 285+40, 285+40, "balaise", black);
    //gdImageString(chart, gdFontSmall, 285+90, 285+90, "le blaise", black);

    //gdImageDashedLine();
    //chart = gdImageScale(chart, 500, 500);

    png_file = fopen("test.png", "wb");

    gdImagePng(chart, png_file);
    fclose(png_file);

    gdImageDestroy(chart);
}

void set_chart_value(char *name, char *percentage)
{
    int n;
    int x = 0;
    int y;

    chart = gdImageCreate(500, 500);
    int perc = *((int*)percentage);
    y = (perc*360)/100;

    // add system to change colors
    gdImageFilledArc(chart, 250, 250, 250, 250, x, y, navy, gdPie);
    gdImageArc(chart, 250, 250, 250, 250, 0, 360, black);
    x = y;
    printf("%s \n", percentage);
    create_chart(chart);

}

int user_choice(int argc, char *argv[])
{
    const char *separators = " ";
    //char *name_arg = strtok(argv[1], separators);
    char *perc_arg = strtok(argv[2], separators);
    //char *color_arg = strtok(argv[3], separators);

    char *name_arg = "4";

    while(perc_arg != NULL){
        set_chart_value(name_arg, perc_arg);
        perc_arg = strtok(NULL, separators);

        //name_arg = strtok(NULL, separators);
    }

    return 0;
}
*/

