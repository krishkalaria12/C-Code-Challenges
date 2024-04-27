#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store customer details
struct Customer {
    int customerID;
    char name[50];
    char address[100];
    char phone[15];
};

// Structure to store product details
struct Product {
    int productID;
    char name[50];
    float price;
    int quantity;
};

// Structure to store bill details
struct Bill {
    int billNumber;
    float totalAmount;
    struct Customer customer;
    int numProducts;
    struct Product *products;
};

// Function to read customer details
void readCustomerDetails(struct Customer *customer) {
    printf("Enter Customer ID: ");
    scanf("%d", &customer->customerID);
    printf("Enter Customer Name: ");
    scanf(" %[^\n]", customer->name);
    printf("Enter Customer Address: ");
    scanf(" %[^\n]", customer->address);
    printf("Enter Customer Phone Number: ");
    scanf("%s", customer->phone);
}

// Function to read product details
void readProductDetails(struct Product *product) {
    printf("Enter Product ID: ");
    scanf("%d", &product->productID);
    printf("Enter Product Name: ");
    scanf(" %[^\n]", product->name);
    printf("Enter Product Price: ");
    scanf("%f", &product->price);
    printf("Enter Product Quantity: ");
    scanf("%d", &product->quantity);
}

// Function to display bill details of a customer
void displayBill(struct Bill *bill) {
    printf("\nBill Number: %d\n", bill->billNumber);
    printf("\nProducts:\n");
    for (int i = 0; i < bill->numProducts; i++) {
        printf("Product ID: %d, Name: %s, Price: %.2f, Quantity: %d, Amount: %.2f\n",
                bill->products[i].productID, bill->products[i].name,
                bill->products[i].price, bill->products[i].quantity,
                bill->products[i].price * bill->products[i].quantity);
    }
    printf("\nTotal Bill Amount: %.2f\n", bill->totalAmount);
}

// Function to find costliest and cheapest products
void findCostliestAndCheapest(struct Bill *bill) {
    float maxPrice = bill->products[0].price;
    float minPrice = bill->products[0].price;
    int costliestIndex = 0, cheapestIndex = 0;
    for (int i = 1; i < bill->numProducts; i++) {
        if (bill->products[i].price > maxPrice) {
            maxPrice = bill->products[i].price;
            costliestIndex = i;
        }
        if (bill->products[i].price < minPrice) {
            minPrice = bill->products[i].price;
            cheapestIndex = i;
        }
    }
    printf("\nCostliest Product:\n");
    printf("Product ID: %d, Name: %s, Price: %.2f\n",
           bill->products[costliestIndex].productID,
           bill->products[costliestIndex].name, maxPrice);
    printf("\nCheapest Product:\n");
    printf("Product ID: %d, Name: %s, Price: %.2f\n",
           bill->products[cheapestIndex].productID,
           bill->products[cheapestIndex].name, minPrice);
}

// Function to calculate total bill amount
float calculateTotalBill(struct Bill *bill) {
    float total = 0;
    for (int i = 0; i < bill->numProducts; i++) {
        total += bill->products[i].price * bill->products[i].quantity;
    }
    bill->totalAmount = total;
    return total;
}

// Function to free dynamically allocated memory
void freeMemory(struct Bill *bill) {
    free(bill->products);
}

int main() {
    // Customer 1
    struct Bill customer1Bill;
    readCustomerDetails(&customer1Bill.customer);
    printf("Enter Bill Number for Customer 1: ");
    scanf("%d", &customer1Bill.billNumber);
    printf("Enter number of products for Customer 1: ");
    scanf("%d", &customer1Bill.numProducts);
    customer1Bill.products = (struct Product *)malloc(customer1Bill.numProducts * sizeof(struct Product));
    for (int i = 0; i < customer1Bill.numProducts; i++) {
        printf("\nProduct %d details for Customer 1:\n", i + 1);
        readProductDetails(&customer1Bill.products[i]);
    }
    readCustomerDetails(&customer1Bill.customer);
    calculateTotalBill(&customer1Bill);

    // Customer 2
    struct Bill customer2Bill;
    readCustomerDetails(&customer2Bill.customer);
    printf("Enter Bill Number for Customer 2: ");
    scanf("%d", &customer2Bill.billNumber);
    printf("Enter number of products for Customer 2: ");
    scanf("%d", &customer2Bill.numProducts);
    customer2Bill.products = (struct Product *)malloc(customer2Bill.numProducts * sizeof(struct Product));
    for (int i = 0; i < customer2Bill.numProducts; i++) {
        printf("\nProduct %d details for Customer 2:\n", i + 1);
        readProductDetails(&customer2Bill.products[i]);
    }
    readCustomerDetails(&customer2Bill.customer);
    calculateTotalBill(&customer2Bill);

    // Display bills of both customers
    printf("\nBill details for Customer 1:\n");
    displayBill(&customer1Bill);
    findCostliestAndCheapest(&customer1Bill);

    printf("\nBill details for Customer 2:\n");
    displayBill(&customer2Bill);
    findCostliestAndCheapest(&customer2Bill);

    // Calculate total bill amount of both customers
    float totalBillAmount = customer1Bill.totalAmount + customer2Bill.totalAmount;
    printf("\nTotal Bill Amount for both customers: %.2f\n", totalBillAmount);

    // Free dynamically allocated memory
    freeMemory(&customer1Bill);
    freeMemory(&customer2Bill);

    return 0;
}
