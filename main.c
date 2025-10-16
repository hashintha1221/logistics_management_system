#include <stdio.h>
#include <stdlib.h>
#define MAX_CITIES 30

char cities[MAX_CITIES][50];
float dist[MAX_CITIES][MAX_CITIES];
int cityCount = 0;


//function declarations
void addCity();
void listCities();
void editDistance();
void showDistanceTable();
void showVehicles();
void addDelivery();
void showDeliveries();
void showReport();

int main()
{
    int choice;
    while (1) {
        printf("\n==== LOGISTICS MANAGEMENT SYSTEM ====\n");
        printf("1. Add City\n");
        printf("2. Edit Distance\n");
        printf("3. Show Distance Table\n");
        printf("4. Add Delivery\n");
        printf("5. Show Deliveries\n");
        printf("6. Show Report\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addCity();
                  break;
            case 2: editDistance();
                  break;
            case 3: showDistanceTable();
                  break;
            case 4: addDelivery();
                  break;
            case 5: showDeliveries();
                  break;
            case 6: showReport();
                  break;
            case 0:
                 return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

}

   //city function
void addCity() {
    if (cityCount >= MAX_CITIES) {
        printf("City limit reached!\n");
        return;
    }
    char name[50];
    printf("Enter city name: ");
    scanf("%s", name);

    // Check for duplicates
    for (int i = 0; i < cityCount; i++) {
        if (strcmp(cities[i], name) == 0) {
            printf("City already exists!\n");
            return;
        }
    }

    strcpy(cities[cityCount++], name);
    printf("City added successfully!\n");
}



void listCities() {
    printf("\nCities:\n");
    for (int i = 0; i < cityCount; i++) {
        printf("%d. %s\n", i, cities[i]);
    }
}


void editDistance() {
    if (cityCount < 2) {
        printf("Add at least 2 cities first!\n");
        return;
    }
    listCities();
    int i, j;
    float d;
    printf("Enter source city index: ");
    scanf("%d", &i);
    printf("Enter destination city index: ");
    scanf("%d", &j);

    if (i == j) {
        printf("Distance to same city = 0\n");
        dist[i][j] = 0;
        return;
    }

    printf("Enter distance between %s and %s (km): ", cities[i], cities[j]);
    scanf("%f", &d);
    dist[i][j] = dist[j][i] = d;
    printf("Distance updated!\n");
}



void showDistanceTable() {
    if (cityCount == 0) {
        printf("No cities to show!\n");
        return;
    }
    printf("\nDistance Table (km):\n");
    printf("%-10s", "");
    for (int i = 0; i < cityCount; i++)
        printf("%-10s", cities[i]);
    printf("\n");

    for (int i = 0; i < cityCount; i++) {
        printf("%-10s", cities[i]);
        for (int j = 0; j < cityCount; j++) {
            printf("%-10.1f", dist[i][j]);
        }
        printf("\n");
    }
}


void showVehicles() {
    printf("Vehicles displayed\n");
}

void addDelivery() {
    printf("Delivery added!\n");
}

void showDeliveries() {
    printf("All deliveries shown\n");
}

void showReport() {
    printf("Report displayed\n");
}

