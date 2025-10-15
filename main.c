#include <stdio.h>
#include <stdlib.h>


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
 void addCity() {
    printf("City added!\n");
}

void listCities() {
    printf("List of cities\n");
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

