#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "employee_data.dat"

// Structure to represent an employee
struct Employee {
    int empID;
    char name[50];
    float salary;
};

// Function to add a new employee record to the file
void addEmployee() {
    FILE *file = fopen(FILE_NAME, "ab");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    struct Employee emp;

    printf("Enter employee ID: ");
    scanf("%d", &emp.empID);
    fflush(stdin); // Clear the input buffer

    printf("Enter employee name: ");
    fgets(emp.name, sizeof(emp.name), stdin);

    printf("Enter employee salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(struct Employee), 1, file);

    fclose(file);

    printf("Employee added successfully.\n");
}

// Function to display details of a specific employee
void displayEmployee(int empID) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    struct Employee emp;
    int found = 0;

    while (fread(&emp, sizeof(struct Employee), 1, file) == 1) {
        if (emp.empID == empID) {
            found = 1;
            printf("Employee ID: %d\n", emp.empID);
            printf("Employee Name: %s", emp.name);
            printf("Employee Salary: %.2f\n", emp.salary);
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", empID);
    }

    fclose(file);
}

int main() {
    int choice, empID;

    do {
        printf("\n1. Add Employee\n");
        printf("2. Display Employee\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                printf("Enter employee ID: ");
                scanf("%d", &empID);
                displayEmployee(empID);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

