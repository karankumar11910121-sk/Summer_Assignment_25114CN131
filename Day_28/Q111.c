// Q111. WAP to create ticket booking system.

#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAX_SEATS 60
#define BASE_FARE_PER_KM 2.50f

struct Ticket
{
    int ticketId;
    char passengerName[50];
    int passengerAge;
    char source[50];
    char destination[50];
    char journeyDate[12];
    char vehicleNumber[20];
    int seatNumber;
    float distance;
    float fare;
};

void removeNewline(char text[])
{
    text[strcspn(text, "\n")] = '\0';
}

void readText(char prompt[], char text[], int size)
{
    char input[100];

    do
    {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);

        if(strchr(input, '\n') == NULL)
        {
            int ch;

            while((ch = getchar()) != '\n' && ch != EOF)
            {
            }
        }

        removeNewline(input);

        if(strlen(input) == 0)
        {
            printf("Input cannot be empty. Please try again.\n");
        }
        else if(strlen(input) >= (size_t)size)
        {
            printf("Input is too long. Maximum %d characters allowed.\n", size - 1);
            input[0] = '\0';
        }
        else
        {
            strcpy(text, input);
        }
    } while(strlen(input) == 0);
}

int readInt(char prompt[], int min, int max)
{
    char input[50];
    int value;
    char extra;

    while(1)
    {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);

        if(sscanf(input, "%d %c", &value, &extra) == 1 && value >= min && value <= max)
        {
            return value;
        }

        printf("Please enter a valid number between %d and %d.\n", min, max);
    }
}

float readFloat(char prompt[], float min)
{
    char input[50];
    float value;
    char extra;

    while(1)
    {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);

        if(sscanf(input, "%f %c", &value, &extra) == 1 && value >= min)
        {
            return value;
        }

        printf("Please enter a valid amount greater than or equal to %.2f.\n", min);
    }
}

int isValidDate(char date[])
{
    int day, month, year;
    char extra;

    if(strlen(date) != 10)
    {
        return 0;
    }

    if(date[2] != '-' || date[5] != '-')
    {
        return 0;
    }

    if(sscanf(date, "%2d-%2d-%4d %c", &day, &month, &year, &extra) != 3)
    {
        return 0;
    }

    if(year < 2026 || month < 1 || month > 12 || day < 1 || day > 31)
    {
        return 0;
    }

    if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        return 0;
    }

    if(month == 2)
    {
        int leapYear = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);

        if(day > (leapYear ? 29 : 28))
        {
            return 0;
        }
    }

    return 1;
}

void readDate(char prompt[], char date[])
{
    while(1)
    {
        readText(prompt, date, 11);

        if(isValidDate(date))
        {
            return;
        }

        printf("Please enter a valid date in DD-MM-YYYY format.\n");
    }
}

float calculateFare(float distance, int age)
{
    float fare = distance * BASE_FARE_PER_KM;

    if(age < 12)
    {
        fare = fare * 0.50f;
    }
    else if(age >= 60)
    {
        fare = fare * 0.70f;
    }

    return fare;
}

int findTicketById(struct Ticket ticket[], int count, int ticketId)
{
    int i;

    for(i = 0; i < count; i++)
    {
        if(ticket[i].ticketId == ticketId)
        {
            return i;
        }
    }

    return -1;
}

int isSeatBooked(struct Ticket ticket[], int count, char vehicleNumber[], char journeyDate[], int seatNumber, int ignoreIndex)
{
    int i;

    for(i = 0; i < count; i++)
    {
        if(i != ignoreIndex &&
           ticket[i].seatNumber == seatNumber &&
           strcmp(ticket[i].vehicleNumber, vehicleNumber) == 0 &&
           strcmp(ticket[i].journeyDate, journeyDate) == 0)
        {
            return 1;
        }
    }

    return 0;
}

void showSeatAvailability(struct Ticket ticket[], int count)
{
    char vehicleNumber[20];
    char journeyDate[12];
    int bookedSeats = 0;
    int i;

    readText("\nEnter Vehicle Number: ", vehicleNumber, sizeof(vehicleNumber));
    readDate("Enter Journey Date (DD-MM-YYYY): ", journeyDate);

    for(i = 0; i < count; i++)
    {
        if(strcmp(ticket[i].vehicleNumber, vehicleNumber) == 0 &&
           strcmp(ticket[i].journeyDate, journeyDate) == 0)
        {
            bookedSeats++;
        }
    }

    printf("\nTotal Seats     : %d", MAX_SEATS);
    printf("\nBooked Seats    : %d", bookedSeats);
    printf("\nAvailable Seats : %d\n", MAX_SEATS - bookedSeats);
}

void printTicket(struct Ticket ticket)
{
    printf("\n====================================");
    printf("\n             TICKET");
    printf("\n====================================");
    printf("\nBooking ID      : %d", ticket.ticketId);
    printf("\nPassenger Name  : %s", ticket.passengerName);
    printf("\nPassenger Age   : %d", ticket.passengerAge);
    printf("\nSource          : %s", ticket.source);
    printf("\nDestination     : %s", ticket.destination);
    printf("\nJourney Date    : %s", ticket.journeyDate);
    printf("\nVehicle Number  : %s", ticket.vehicleNumber);
    printf("\nSeat Number     : %d", ticket.seatNumber);
    printf("\nDistance        : %.2f km", ticket.distance);
    printf("\nFare            : %.2f", ticket.fare);
    printf("\n====================================\n");
}

void readTicketDetails(struct Ticket ticket[], int count, int index, int isUpdate)
{
    int seatNumber;

    readText("Enter Passenger Name: ", ticket[index].passengerName, sizeof(ticket[index].passengerName));
    ticket[index].passengerAge = readInt("Enter Passenger Age: ", 1, 120);
    readText("Enter Source: ", ticket[index].source, sizeof(ticket[index].source));
    readText("Enter Destination: ", ticket[index].destination, sizeof(ticket[index].destination));
    readDate("Enter Journey Date (DD-MM-YYYY): ", ticket[index].journeyDate);
    readText("Enter Vehicle Number (Train/Bus/Flight): ", ticket[index].vehicleNumber, sizeof(ticket[index].vehicleNumber));

    while(1)
    {
        seatNumber = readInt("Enter Seat Number: ", 1, MAX_SEATS);

        if(!isSeatBooked(ticket, count, ticket[index].vehicleNumber, ticket[index].journeyDate, seatNumber, isUpdate ? index : -1))
        {
            ticket[index].seatNumber = seatNumber;
            break;
        }

        printf("This seat is already booked for the same vehicle and date. Choose another seat.\n");
    }

    ticket[index].distance = readFloat("Enter Distance in KM: ", 1.0f);
    ticket[index].fare = calculateFare(ticket[index].distance, ticket[index].passengerAge);
}

int main(void)
{
    struct Ticket ticket[MAX];
    int choice;
    int count = 0;
    int nextTicketId = 1001;
    int i, ticketId, index;
    float totalRevenue;

    do
    {
        printf("\n===============================");
        printf("\n     TICKET BOOKING SYSTEM");
        printf("\n===============================");
        printf("\n1. Book Ticket");
        printf("\n2. View All Tickets");
        printf("\n3. Search Ticket");
        printf("\n4. Update Ticket");
        printf("\n5. Cancel Ticket");
        printf("\n6. Seat Availability");
        printf("\n7. Print Ticket");
        printf("\n8. Total Revenue");
        printf("\n9. Exit");
        printf("\n");

        choice = readInt("Enter Your Choice: ", 1, 9);

        switch(choice)
        {
            case 1:
                if(count >= MAX)
                {
                    printf("\nTicket List is Full!\n");
                    break;
                }

                ticket[count].ticketId = nextTicketId++;
                printf("\nAuto Booking ID: %d\n", ticket[count].ticketId);

                readTicketDetails(ticket, count, count, 0);
                count++;

                printf("\nTicket Booked Successfully!");
                printf("\nAutomatic Fare: %.2f\n", ticket[count - 1].fare);
                printTicket(ticket[count - 1]);
                break;

            case 2:
                if(count == 0)
                {
                    printf("\nNo Ticket Bookings Found!\n");
                }
                else
                {
                    printf("\n========== BOOKED TICKETS ==========\n");

                    for(i = 0; i < count; i++)
                    {
                        printTicket(ticket[i]);
                    }
                }
                break;

            case 3:
                if(count == 0)
                {
                    printf("\nNo Ticket Bookings Found!\n");
                    break;
                }

                ticketId = readInt("\nEnter Booking ID to Search: ", 1, 999999);
                index = findTicketById(ticket, count, ticketId);

                if(index != -1)
                {
                    printf("\nTicket Found\n");
                    printTicket(ticket[index]);
                }
                else
                {
                    printf("\nTicket Not Found!\n");
                }
                break;

            case 4:
                if(count == 0)
                {
                    printf("\nNo Ticket Bookings Found!\n");
                    break;
                }

                ticketId = readInt("\nEnter Booking ID to Update: ", 1, 999999);
                index = findTicketById(ticket, count, ticketId);

                if(index != -1)
                {
                    readTicketDetails(ticket, count, index, 1);
                    printf("\nTicket Updated Successfully!");
                    printf("\nNew Automatic Fare: %.2f\n", ticket[index].fare);
                }
                else
                {
                    printf("\nTicket Not Found!\n");
                }
                break;

            case 5:
                if(count == 0)
                {
                    printf("\nNo Ticket Bookings Found!\n");
                    break;
                }

                ticketId = readInt("\nEnter Booking ID to Cancel: ", 1, 999999);
                index = findTicketById(ticket, count, ticketId);

                if(index != -1)
                {
                    for(i = index; i < count - 1; i++)
                    {
                        ticket[i] = ticket[i + 1];
                    }

                    count--;
                    printf("\nTicket Cancelled Successfully!\n");
                }
                else
                {
                    printf("\nTicket Not Found!\n");
                }
                break;

            case 6:
                showSeatAvailability(ticket, count);
                break;

            case 7:
                if(count == 0)
                {
                    printf("\nNo Ticket Bookings Found!\n");
                    break;
                }

                ticketId = readInt("\nEnter Booking ID to Print: ", 1, 999999);
                index = findTicketById(ticket, count, ticketId);

                if(index != -1)
                {
                    printTicket(ticket[index]);
                }
                else
                {
                    printf("\nTicket Not Found!\n");
                }
                break;

            case 8:
                totalRevenue = 0;

                for(i = 0; i < count; i++)
                {
                    totalRevenue += ticket[i].fare;
                }

                printf("\nTotal Booked Tickets : %d", count);
                printf("\nTotal Revenue        : %.2f\n", totalRevenue);
                break;

            case 9:
                printf("\nThank You for Using Ticket Booking System.\n");
                break;
        }

    } while(choice != 9);

    return 0;
 }