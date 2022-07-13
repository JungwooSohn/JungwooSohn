#include <stdio.h>
#include <stdbool.h>

typedef unsigned int Pdata;


int main(void) {

    Pdata hp_hero, atk_hero, hp_devil, atk_devil, p, s, hero_attack_count = 0, devil_attack_count = 0, less;
    scanf("%u%u%u%u%u%u", &hp_hero, &atk_hero, &hp_devil, &atk_devil, &p, &s);

    if ((less = hp_devil % atk_hero) != 0) {
        if (less <= p) {
            hp_devil += s;
        }
    } else {
        if (atk_hero <= p) {
            hp_devil += s;
        }
    }

    hero_attack_count = hp_devil / atk_hero;
    devil_attack_count = hp_hero / atk_devil;

    if (hp_devil % atk_hero != 0) {
        hero_attack_count++;
    }

    if (hp_hero % atk_devil != 0) {
        devil_attack_count++;
    }




    if (hero_attack_count <= devil_attack_count) {
        printf("Victory!");
    } else {
        printf("gg");
    }


    return 0;
}