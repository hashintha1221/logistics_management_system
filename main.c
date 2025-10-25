#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strcmp(), strcpy()
#define MAX_CITIES 30
#define MAX_DELIVERIES 50
#define FUEL_PRICE 310.0
#define INF 1e9

//vehicle Details
typedef struct
{
    char name[10];
    int capacity;
    float rate;
    float speed;
    float efficiency;
}  Vehicle;

//delivery details
typedef struct
{
    int src, dest;
    float weight;
    int vehicleType;
    float distance;
    float cost;
    float fuelUsed;
    float fuelCost;
    float totalCost;
    float profit;
    float customerCharge;
    float time;
} Delivery;

//Global Arrays
char cities[MAX_CITIES][50];
float dist[MAX_CITIES][MAX_CITIES];
int cityCount = 0;
Delivery deliveries[MAX_DELIVERIES];
int deliveryCount = 0;

Vehicle vehicles[3] =
{
    {"Van", 1000, 30, 60, 12},
    {"Truck", 5000, 40, 50, 6},
    {"Lorry", 10000, 80, 45, 4}
};



//function declarations
void manageCities();
void addCity();
void renameCity();
void removeCity();
void listCities();
void editDistance();
void showDistanceTable();
void showVehicles();
void addDelivery();
void showDeliveries();
void showReport();
void saveDeliveries();
void loadDeliveries();
void findLeastCostRoute();

//main menu
int main()
{
    int choice;
    while (1) {
        printf("Welcome to Logistics Management System by Hashintha Dilshan\n");
        printf("------------------------------------------------------\n");
        printf("1. Manage Cities\n");
        printf("2. Edit Distance\n");
        printf("3. Show Distance Table\n");
        printf("4. Add Delivery\n");
        printf("5. Show Deliveries\n");
        printf("6. Show Report\n");
        printf("7. Save Deliveries\n");
        printf("8. Load Deliveries\n");
        printf("9. Find Least Cost Route\n");
        printf("0. Exit\n");
        printf("========================================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: manageCities();
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
            case 7: saveDeliveries();
                  break;
            case 8: loadDeliveries();
                  break;
            case 9: findLeastCostRoute();
                   break;
            case 0:
                 return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

}

   //......city management......

   void manageCities() {
    int ch;
    while (1) {
        printf("\n=== CITY MANAGEMENT ===\n");
        printf("1. Add City\n");
        printf("2. Rename City\n");
        printf("3. Remove City\n");
        printf("4. List Cities\n");
        printf("0. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        if (ch == 0)
            break;
        else if (ch == 1)
            addCity();
        else if (ch == 2)
            renameCity();
        else if (ch == 3)
            removeCity();
        else if (ch == 4)
            listCities();
        else
            printf("Invalid choice!\n");
    }
}
// rename city
void renameCity() {
    if (cityCount == 0) {
        printf("No cities available to rename!\n");
        return;
    }

    listCities();
    int index;
    printf("Enter city index to rename: ");
    scanf("%d", &index);

    if (index < 0 || index >= cityCount) {
        printf("Invalid city index!\n");
        return;
    }

    char newName[50];
    printf("Enter new name for %s: ", cities[index]);
    scanf("%s", newName);

    // Check for duplicates
    for (int i = 0; i < cityCount; i++) {
        if (strcmp(cities[i], newName) == 0) {
            printf("City name already exists!\n");
            return;
        }
    }

    strcpy(cities[index], newName);
    printf("City renamed successfully!\n");
}

void removeCity() {
    if (cityCount == 0) {
        printf("No cities available to remove!\n");
        return;
    }

    listCities();
    int index;
    printf("Enter city index to remove: ");
    scanf("%d", &index);

    if (index < 0 || index >= cityCount) {
        printf("Invalid city index!\n");
        return;
    }

    // Shift cities and distance table
    for (int i = index; i < cityCount - 1; i++) {
        strcpy(cities[i], cities[i + 1]);
        for (int j = 0; j < cityCount; j++) {
            dist[i][j] = dist[i + 1][j];
            dist[j][i] = dist[j][i + 1];
        }
    }
    cityCount--;
    printf("City removed successfully!\n");
}


// add new city
void addCity() {
    if (cityCount >= MAX_CITIES) {
        printf("City limit reached!\n");
        return;
    }
    char name[50];
    printf("Enter city name: ");
    scanf("%s", name);


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

//distance edit
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


//distance table
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

//vehicle info
void showVehicles() {
    printf("\nAvailable Vehicle\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s - Capacity: %dkg | Rate: %.2f LKR/km | Speed: %.0f km/h | Efficiency: %.1f km/l\n",
            i + 1,
            vehicles[i].name,
            vehicles[i].capacity,
            vehicles[i].rate,
            vehicles[i].speed,
            vehicles[i].efficiency);
    }
}


void addDelivery() {

    if (cityCount < 2) {
        printf("Add cities and distances first!\n");
        return;
    }

    Delivery d;
    listCities();
    printf("Enter source index: ");
    scanf("%d", &d.src);
    printf("Enter destination index: ");
    scanf("%d", &d.dest);

    if (d.src == d.dest) {
        printf("Source and destination must be different!\n");
        return;
    }

    printf("Enter weight (kg): ");
    scanf("%f", &d.weight);

    showVehicles();
    printf("Select vehicle (1=Van, 2=Truck, 3=Lorry): ");
    scanf("%d", &d.vehicleType);


    // Add this inside addDelivery() before using Vehicle v
if (d.vehicleType < 1 || d.vehicleType > 3) {
    printf("Invalid vehicle type! Please select 1, 2, or 3.\n");
    return;
}

if (d.weight <= 0) {
    printf("Weight must be greater than 0!\n");
    return;
}

if (d.src < 0 || d.src >= cityCount || d.dest < 0 || d.dest >= cityCount) {
    printf("Invalid city index!\n");
    return;
}

if (dist[d.src][d.dest] <= 0) {
    printf("No valid distance between selected cities!\n");
    return;
}


    // Vehicle selection
    Vehicle v = vehicles[d.vehicleType - 1];

    // Check capacity
    if (d.weight > v.capacity) {
        printf("Weight exceeds vehicle capacity!\n");
        return;
    }

    // Get distance
    d.distance = dist[d.src][d.dest];
    if (d.distance <= 0) {
        printf("Distance not found! selected cities!\n");
        return;
    }

    // Calculation
    d.cost = d.distance * v.rate * (1 + d.weight / 10000.0);
    d.fuelUsed = d.distance / v.efficiency;
    d.fuelCost = d.fuelUsed * FUEL_PRICE;
    d.totalCost = d.cost + d.fuelCost;
    d.profit = d.cost * 0.25;
    d.customerCharge = d.totalCost + d.profit;
    d.time = d.distance / v.speed;

    deliveries[deliveryCount++] = d;

    //Summary output
    printf("\n--- DELIVERY SUMMARY ---\n");
    printf("From: %s\nTo: %s\n", cities[d.src], cities[d.dest]);
    printf("Vehicle: %s\n", v.name);
    printf("Weight: %.1f kg\nDistance: %.1f km\n", d.weight, d.distance);
    printf("Transport Cost: %.2f LKR\n", d.cost);
    printf("Fuel Used: %.2f L\nFuel Cost: %.2f LKR\n", d.fuelUsed, d.fuelCost);
    printf("Total Operational Cost: %.2f LKR\n", d.totalCost);
    printf("Profit: %.2f LKR\nCustomer Charge: %.2f LKR\n", d.profit, d.customerCharge);
    printf("Estimated Time: %.2f hours\n", d.time);
    printf("-----------------------------\n");
}


//show all delivers
void showDeliveries() {
    if (deliveryCount == 0) {
    printf("No deliveries yet!\n");
    return;
    }

  printf("\n ALL DELIVERIES:\n");
    for (int i = 0; i < deliveryCount; i++) {
      Delivery d = deliveries[i];
      printf("\nDelivery #%d\n", i + 1);
      printf("From: %s -> %s\n", cities[d.src], cities[d.dest]);
      printf("Vehicle: %s\n", vehicles[d.vehicleType - 1].name);
      printf("Weight: %.1f kg | Distance: %.1f km\n", d.weight, d.distance);
      printf("Charge: %.2f LKR | Profit: %.2f LKR | Time: %.2f hrs\n", d.customerCharge, d.profit, d.time);
    }
    printf("========================\n");
}

//report function
void showReport() {

if (deliveryCount == 0) {
        printf("No deliveries to report!\n");
        return;
    }

  float totalDist = 0, totalProfit = 0, totalTime = 0;
  for (int i = 0; i < deliveryCount; i++) {
    totalDist += deliveries[i].distance;
    totalProfit += deliveries[i].profit;
    totalTime += deliveries[i].time;
    }

    printf("\n==== PERFORMANCE REPORT ====\n");
    printf("Total Deliveries: %d\n", deliveryCount);
    printf("Total Distance: %.1f km\n", totalDist);
    printf("Average Time: %.2f hours\n", totalTime / deliveryCount);
    printf("Total Profit: %.2f LKR\n", totalProfit);
    printf("============================\n");
}

//-------File Handling------

void saveDeliveries() {
    FILE *fp = fopen("deliveries.txt", "w");
    if (fp == NULL) {
        printf("Error saving deliveries!\n");
        return;
    }

    for (int i = 0; i < deliveryCount; i++) {
        Delivery d = deliveries[i];
        fprintf(fp, "%d %d %f %d %f %f %f %f %f %f %f\n",
                d.src, d.dest, d.weight, d.vehicleType, d.distance,
                d.cost, d.fuelUsed, d.fuelCost, d.totalCost, d.profit,
                d.customerCharge);
    }

    fclose(fp);
    printf("Deliveries saved to file successfully!\n");
}

void loadDeliveries() {
    FILE *fp = fopen("deliveries.txt", "r");
    if (fp == NULL) {
        printf("No previous delivery data found.\n");
        return;
    }

    deliveryCount = 0;
    while (fscanf(fp, "%d %d %f %d %f %f %f %f %f %f %f",
                  &deliveries[deliveryCount].src,
                  &deliveries[deliveryCount].dest,
                  &deliveries[deliveryCount].weight,
                  &deliveries[deliveryCount].vehicleType,
                  &deliveries[deliveryCount].distance,
                  &deliveries[deliveryCount].cost,
                  &deliveries[deliveryCount].fuelUsed,
                  &deliveries[deliveryCount].fuelCost,
                  &deliveries[deliveryCount].totalCost,
                  &deliveries[deliveryCount].profit,
                  &deliveries[deliveryCount].customerCharge) == 11) {
        deliveryCount++;
    }

    fclose(fp);
    printf("Loaded %d deliveries from file.\n", deliveryCount);
}


//shortest path
void findLeastCostRoute() {
    if (cityCount < 2) {
        printf("Add at least 2 cities first!\n");
        return;
    }

    int src, dest;
    listCities();
    printf("Enter source city index: ");
    scanf("%d", &src);
    printf("Enter destination city index: ");
    scanf("%d", &dest);

    if (src == dest) {
        printf("Source and destination must be different!\n");
        return;
    }

    float cost[MAX_CITIES];
    int visited[MAX_CITIES], parent[MAX_CITIES];

    // Initialize arrays
    for (int i = 0; i < cityCount; i++) {
        cost[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    cost[src] = 0;

    // Dijkstra algorithm
    for (int count = 0; count < cityCount - 1; count++) {
        int u = -1;
        float minCost = INF;

        for (int i = 0; i < cityCount; i++)
            if (!visited[i] && cost[i] < minCost) {
                minCost = cost[i];
                u = i;
            }

        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < cityCount; v++) {
            if (!visited[v] && dist[u][v] > 0 &&
                cost[u] + dist[u][v] < cost[v]) {
                cost[v] = cost[u] + dist[u][v];
                parent[v] = u;
            }
        }
    }

    if (cost[dest] == INF) {
        printf("No route found between %s and %s.\n", cities[src], cities[dest]);
        return;
    }

    // Print shortest path
    printf("\nLeast-Cost Route from %s to %s:\n", cities[src], cities[dest]);
    int path[MAX_CITIES], count = 0;
    for (int v = dest; v != -1; v = parent[v])
        path[count++] = v;

    for (int i = count - 1; i >= 0; i--) {
        printf("%s", cities[path[i]]);
        if (i > 0) printf(" -> ");
    }
    printf("\nTotal Distance: %.1f km\n", cost[dest]);
}


