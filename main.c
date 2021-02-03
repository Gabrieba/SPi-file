#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void allocation(char** buf, int taille) {
    *buf = calloc(taille, sizeof(char));
    if (*buf == NULL)
      perror("Erreur d'allocation mémoire");
}


int main() {
  FILE* fp;
  FILE* f1; FILE* f2; FILE* f3; FILE* f4; FILE* f5; FILE* f6; FILE* f7; FILE* f8; FILE* f9;
  char buffer[1000]; char fichier[100];
  char* freq; char* legende1; char* legende2; char* legende3; char* legende4; char* legende5;
  char* legende6; char* legende7; char* legende8;
  const char* separator = " \n";

  allocation(&freq, 100);
  allocation(&legende1, 100);
  allocation(&legende2, 100);
  allocation(&legende3, 100);
  allocation(&legende4, 100);
  allocation(&legende5, 100);
  allocation(&legende6, 100);
  allocation(&legende7, 100);
  allocation(&legende8, 100);

  strcpy(fichier, "resultats_filtre.s2p");
  printf("fichier = %s\n", fichier);
  puts("Nom du fichier d'extension SPi :");
//  scanf("%s", fichier);
  fp = fopen(fichier, "r");
  while (fp == NULL) {
    perror("Erreur lors de l'ouverture du fichier spi ; vérifier son nom.");
    scanf("%s", fichier);
  }

  fgets(buffer, 100, fp);   // Lit la premiere ligne inutile
  fgets(buffer, 100, fp);   // Lit la seconde ligne inutile
  fscanf(fp, "%s %s %s %s %s %s %s %s %s %s", buffer, freq, legende1, legende2, legende3, legende4, legende5, legende6, legende7, legende8);
  fgets(buffer, 5, fp);   // Lit le retour chariot
  fgets(buffer, 100, fp);   // Lit la quatrieme ligne inutile

  f1 = fopen("tmp1.txt", "w");
  if (f1 == NULL) {
    perror("Erreur lors de la création d'un fichier tmp");
    fclose(fp);
    return EXIT_FAILURE;
  }
  f2 = fopen("tmp2.txt", "w");
  if (f2 == NULL) {
    perror("Erreur lors de la création d'un fichier tmp");
    fclose(fp);
    fclose(f1);
    return EXIT_FAILURE;
  }
  f3 = fopen("tmp3.txt", "w");
  if (f3 == NULL) {
    perror("Erreur lors de la création d'un fichier tmp");
    fclose(fp);
    fclose(f1);
    fclose(f2);
    return EXIT_FAILURE;
  }
  f4 = fopen("tmp4.txt", "w");
  if (f4 == NULL) {
    perror("Erreur lors de la création d'un fichier tmp");
    fclose(fp);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    return EXIT_FAILURE;
  }
  f5 = fopen("tmp5.txt", "w");
  if (f5 == NULL) {
    perror("Erreur lors de la création d'un fichier tmp");
    fclose(fp);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    return EXIT_FAILURE;
  }
  f6 = fopen("tmp6.txt", "w");
  if (f6 == NULL) {
    perror("Erreur lors de la création d'un fichier tmp");
    fclose(fp);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
    return EXIT_FAILURE;
  }
  f7 = fopen("tmp7.txt", "w");
  if (f7 == NULL) {
    perror("Erreur lors de la création d'un fichier tmp");
    fclose(fp);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
    fclose(f6);
    return EXIT_FAILURE;
  }
  f8 = fopen("tmp8.txt", "w");
  if (f8 == NULL) {
    perror("Erreur lors de la création d'un fichier tmp");
    fclose(fp);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
    fclose(f6);
    fclose(f7);
    return EXIT_FAILURE;
  }
  f9 = fopen("tmp9.txt", "w");
  if (f9 == NULL) {
    perror("Erreur lors de la création d'un fichier tmp");
    fclose(fp);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
    fclose(f6);
    fclose(f7);
    fclose(f8);
    return EXIT_FAILURE;
  }
  fprintf(f1, "%s\n", freq);        // Ecriture des étiquettes en première ligne de chaque fichier final
  fprintf(f2, "%s\n", legende1);
  fprintf(f3, "%s\n", legende2);
  fprintf(f4, "%s\n", legende3);
  fprintf(f5, "%s\n", legende4);
  fprintf(f6, "%s\n", legende5);
  fprintf(f7, "%s\n", legende6);
  fprintf(f8, "%s\n", legende7);
  fprintf(f9, "%s\n", legende8);

  while (fgets(buffer, 1000, fp) != NULL) {
    freq = strtok(buffer, separator);
    legende1 = strtok(NULL, separator);
    legende2 = strtok(NULL, separator);
    legende3 = strtok(NULL, separator);
    legende4 = strtok(NULL, separator);
    legende5 = strtok(NULL, separator);
    legende6 = strtok(NULL, separator);
    legende7 = strtok(NULL, separator);
    legende8 = strtok(NULL, separator);

    fprintf(f1, "%s\n", freq);
    fprintf(f2, "%s\n", legende1);
    fprintf(f3, "%s\n", legende2);
    fprintf(f4, "%s\n", legende3);
    fprintf(f5, "%s\n", legende4);
    fprintf(f6, "%s\n", legende5);
    fprintf(f7, "%s\n", legende6);
    fprintf(f8, "%s\n", legende7);
    fprintf(f9, "%s\n", legende8);
  }

  fclose(fp);
  fclose(f1);
  fclose(f2);
  fclose(f3);
  fclose(f4);
  fclose(f5);
  fclose(f6);
  fclose(f7);
  fclose(f8);
  fclose(f9);

  puts("Extration des données réussie");
  return EXIT_SUCCESS;
}
