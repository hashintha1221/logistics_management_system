#include <stdio.h>
#include <stdlib.h>
#define MAX_CITIES 30

char cities[MAX_CITIES][50];
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
    printf("Distance edited!\n");
}

void showDistanceTable() {
    printf("Distance table shown\n");
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

