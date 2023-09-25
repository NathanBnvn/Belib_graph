#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <gd.h>
#include <gdfonts.h>
#include <gdfontg.h>
#include <gdfontl.h>

using namespace std;
using json = nlohmann::json;


int white, green, yellow, red, sunny_blue, grey, navy,
    pale_yellow, dark_purple, black, pink, olivine,
    cadet_grey, tyrian_purple, ash_gray,
    light_coral, plum, rose_ebony,
    sienna, cam_blue, brigde_blue;


void create_chart(int countByArrondissements[20])
{

    FILE *image_file;
    gdImagePtr chart;
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


    int colors[20] = {black, yellow, green, grey, navy, sunny_blue,
                      red, pale_yellow, dark_purple, pink,
                      cadet_grey,tyrian_purple, ash_gray,
                      light_coral, plum, rose_ebony, sienna,
                      cam_blue, brigde_blue, olivine};

    int x = 0;
    int y;
    char legend_txt[13];
    char title[62] = "Les bornes de Belib dans Paris par arrondissements";

    int text_y = 60;
    int text_x = 20;
    int color_legend_y_2 = 65;
    int color_legend_y = 70;


    for(int c = 0; c < 20; c++){
        if(countByArrondissements[c] > 0) {
            if(c > 0){
                x = x + y;
            }
            y = (((countByArrondissements[c]/ 19)) * 360) /100;
            gdImageFilledArc(chart, 250, 250, 250, 250, x, y, colors[c], gdPie);

        }

        snprintf(legend_txt, 13, "%d%% - %d Arr.", (countByArrondissements[c]*100) / 1991, c+1);
        gdImageFilledRectangle(chart, 10, color_legend_y, 15, color_legend_y_2, colors[c]);
        gdImageString(chart, gdFontSmall, text_x, text_y, (unsigned char*)legend_txt, black);
        text_y = text_y + 20;
        color_legend_y_2 = color_legend_y_2 + 20;
        color_legend_y = color_legend_y + 20;
    }

    gdImageString(chart, gdFontGiant, 10, 20, (unsigned char*)title, black);
    gdImageSetAntiAliased(chart, gdTrueColorAlpha(255, 0, gdBlueMax, gdAlphaOpaque));

    image_file = fopen("../belib_graph/graph.png", "wb");
    gdImagePng(chart, image_file);
    fclose(image_file);

    gdImageDestroy(chart);
}


void get_count_by_district(json data, int maxCount){
    maxCount = end(data) - begin(data);
    int a = 0, b = 0,c = 0,d = 0,e = 0,f = 0,g = 0,h = 0,i = 0,j = 0,
        k = 0,l = 0,m = 0,n = 0,o = 0,p = 0,q = 0,r = 0,s = 0,t = 0;
    int districts[maxCount];

    for (int i = 0; i < maxCount; i++) {
        if(!data[i]["adresse_station"].empty()){
            string adress = data[i]["adresse_station"].get<std::string>();

            adress.erase(adress.begin(), adress.end()-11);
            adress.erase(adress.begin()+5, adress.end());

            districts[i] = stoi(adress);
        }

        switch(districts[i]){
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

    int countByDistricts[20] = {a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t};

    create_chart(countByDistricts);
}

void get_status(){
    int available=0, occupied=0, unknown=0, maintenance=0, planned=0;
    int  availables[22], occupieds[22], unknowns[22], maintenances[22], planneds[22];
    int max;
    char paths[40];

    for(int n = 1; n < 22; n++){
        snprintf(paths, 40, "../source/september/belib-%d.json", n);
        string path = paths;
        ifstream file(path);
        json data = json::parse(file);

        max = end(data) - begin(data);

        for (int i = 0; i < max; i++) {
            string status = data[i]["statut_pdc"].get<std::string>();
            if(status.empty()){
                cout << 1 << "\n";
                return ;
            }

            if(status == "Occupé (en charge)"){
                occupied = occupied + 1;

            } else if(status == "Disponible"){
                available = available + 1;
            } else if(status == "Inconnu") {
                unknown = unknown + 1;
            } else if(status == "En maintenance"){
                maintenance = maintenance + 1;
            } else if(status == "Mise en service planifiée"){
                planned = planned + 1;
            }
        }

        cout << n << " - " << "occupé : " << occupied << "\n";
        cout << n << " - " << "dispo : " << available << "\n";
        cout << n << " - " << "maintenance :" << maintenance << "\n";
        cout << n << " - " << "mise en service :" << planned << "\n";
    }
}

int main()
{
    ifstream file("../source/belib.json");
    json data = json::parse(file);
    int maxCount;
    maxCount = end(data) - begin(data);

    get_count_by_district(data, maxCount);
    //get_status();
    return 0;
}


