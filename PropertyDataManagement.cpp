#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void clear(){
	getchar(); //buat nunggu input -> enter
	system("cls"); //bersihin layar
}


void menu(){ //print menu yg ada
	printf("What do you want to do?\n"); 
	printf("1. Display data\n"); 
	printf("2. Search Data\n"); 
	printf("3. Sort Data\n"); 
	printf("4. Export Data\n"); 
	printf("5. Exit\n"); 
	printf("Your choice: "); 
}


typedef struct{ //struct to store data
    char location1[100];
    char location2[100];
    int price;
    int rooms;
    int bathrooms;
    int carParks;
    char type[50];
    char furnish[50];
} property; 


void displaydata(property *data, int count){ //display data yg ada 
    int rows;
    do {
        printf("Number of rows: ");
        scanf("%d", &rows);
        if (rows < 1) {
            printf("Invalid! Please enter a positive integer!\n");
        }
    } while (rows < 1); //harus lebih dr 1
	
	//display header
    printf("Location 1                Location 2      Price         Rooms  Bathrooms CarParks    Type            Furnish  \n"); 
    for (int i = 0; i < count && i < rows; i++) { //diplay data"nya 
        printf("%-25s %-15s %-15d %-8d %-8d %-8d %-15s %-15s \n", 
               data[i].location1, data[i].location2, data[i].price, 
               data[i].rooms, data[i].bathrooms, data[i].carParks, 
               data[i].type, data[i].furnish);
    }
    getchar(); 
}


void searchdata(property *data, int count){ //untuk cari data
    char column[20], find[50];  
    int found = 0;

    printf("Choose column (Location1, Location2, Price, Rooms, Bathrooms, CarParks, Type, Furnish): ");
    scanf("%s", column); 
    printf("What data do you want to find? ");
    scanf("%s", find);
	
    for (int i = 0; i < count; i++) { //dicompare pake strcmp & pake atoi juga untuk angka 
        if ((strcmp(column, "Location1") == 0 && strcmp(data[i].location1, find) == 0) ||
            (strcmp(column, "Location2") == 0 && strcmp(data[i].location2, find) == 0) ||
            (strcmp(column, "Price") == 0 && data[i].price == atoi(find)) ||
            (strcmp(column, "Rooms") == 0 && data[i].rooms == atoi(find)) ||
            (strcmp(column, "Bathrooms") == 0 && data[i].bathrooms == atoi(find)) ||
            (strcmp(column, "CarParks") == 0 && data[i].carParks == atoi(find)) ||
            (strcmp(column, "Type") == 0 && strcmp(data[i].type, find) == 0) ||
            (strcmp(column, "Furnish") == 0 && strcmp(data[i].furnish, find) == 0)) {
            
            if (!found){
                printf("Data found. Detail of data:\n");
                printf("Location 1                Location 2      Price         Rooms  Bathrooms CarParks    Type            Furnish  \n"); 
            }
            printf("%-25s %-15s %-15d %-8d %-8d %-8d %-15s %-15s\n", 
                   data[i].location1, data[i].location2, data[i].price, data[i].rooms, 
                   data[i].bathrooms, data[i].carParks, data[i].type, data[i].furnish);
            found = 1;
        }
    }

    if (!found){
        printf("Data not found!\n");
    }
    getchar(); 
}


void sortdata(property *data, int count, const char *column, const char *order){ //untuk sort data 
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int swap = 0;
            
			if (strcmp(column, "Location1") == 0){ //dicompare 
			    if (strcmp(data[j].location1, data[j + 1].location1) > 0) {
			        swap = 1; 
			    } else {
			        swap = 0; 
			    }
			} 
			else if (strcmp(column, "Location2") == 0){
			    if (strcmp(data[j].location2, data[j + 1].location2) > 0) {
			        swap = 1; 
			    } else {
			        swap = 0; 
			    }
			} 
			else if (strcmp(column, "Price") == 0){
			    if (data[j].price > data[j + 1].price) {
			        swap = 1; 
			    } else {
			        swap = 0; 
			    }
			} 
			else if (strcmp(column, "Rooms") == 0){
			    if (data[j].rooms > data[j + 1].rooms) {
			        swap = 1; 
			    } else {
			        swap = 0; 
			    }
			} 
			else if (strcmp(column, "Bathrooms") == 0){
			    if (data[j].bathrooms > data[j + 1].bathrooms){
			        swap = 1; 
			    } else {
			        swap = 0; 
			    }
			} 
			else if (strcmp(column, "CarParks") == 0){
			    if (data[j].carParks > data[j + 1].carParks){
			        swap = 1; 
			    } else {
			        swap = 0; 
			    }
			} 
			else if (strcmp(column, "Type") == 0){
			    if (strcmp(data[j].type, data[j + 1].type) > 0){
			        swap = 1; 
			    } else {
			        swap = 0; 
			    }
			} 
			else if (strcmp(column, "Furnish") == 0){
			    if (strcmp(data[j].furnish, data[j + 1].furnish) > 0){
			        swap = 1; 
			    } else {
			        swap = 0; 
			    }
			}
		
		    //swap data kalau emang perlu
		    if ((strcmp(order, "asc") == 0 && swap) || (strcmp(order, "dsc") == 0 && !swap)){
		        property temp = data[j];
		        data[j] = data[j + 1];
		        data[j + 1] = temp;
		    }
        }
    }

    printf("Data found & sorted. Detail of data:\n"); //tampilin 10 data yg sudah ke sorted
    printf("Location 1                Location 2      Price         Rooms  Bathrooms CarParks    Type            Furnish  \n");
    for (int i = 0; i < 10; i++){
        printf("%-25s %-15s %-15d %-8d %-8d %-8d %-15s %-15s \n",
               data[i].location1, data[i].location2, data[i].price, data[i].rooms,
               data[i].bathrooms, data[i].carParks, data[i].type, data[i].furnish);
    }
    getchar(); 
}


void exportdata(){ //write the data into a .csv file (in the same directory as the program) ->nyalin data aja 
    char filename[100];
    FILE *filelama = fopen("file.csv", "r");
    if (filelama == NULL) {
        printf("Error! Tidak bisa baca file\n");
        return;
    }

    printf("File name (without extension): ");
    scanf("%s", filename);
    
    strcat(filename, ".csv"); //nambahin .csv dibelakang 

    FILE *filebaru = fopen(filename, "w");
    if (filebaru == NULL){
        printf("Error! Tidak bisa buat file\n");
        fclose(filebaru);
        return;
    }
	
	//copy data yg dulu ke yang baru 
    char line[256];
    while (fgets(line, sizeof(line), filelama) != NULL){
        fputs(line, filebaru);
    }

    fclose(filelama);
    fclose(filebaru);
    printf("Data successfully exported to %s!", filename);
    getchar(); 
}


//void exportdata(property *data, int count, int sorted) { //Kalau pengen yg ke sorted 
//    char filename[100];
//
//    printf("File name (without extension): ");
//    scanf("%s", filename);
//
//    strcat(filename, ".csv"); //nambahin .csv dibelakang 
//
//    if (!sorted){ //jika user belum melakukan sorted data
//    	printf("Eror! Anda belum melakukan sorted data!"); 
//    	getchar(); 
//        return; 
//    }
//
//    FILE *filebaru = fopen(filename, "w");
//    if (filebaru == NULL){
//        printf("Error! Tidak bisa buat file\n");
//        fclose(filebaru);
//        return;
//    }
//
//    fprintf(filebaru, "Location1,Location2,Price,Rooms,Bathrooms,CarParks,Type,Furnish\n");
//
//    for (int i = 0; i < count; i++) { //nulis data yg udh ke sorted
//        fprintf(filebaru, "%s,%s,%d,%d,%d,%d,%s,%s\n",
//                data[i].location1, data[i].location2, data[i].price, data[i].rooms,
//                data[i].bathrooms, data[i].carParks, data[i].type, data[i].furnish);
//    }
//
//    fclose(filebaru);
//    printf("Data successfully exported to %s!", filename);
//    getchar(); 
//}


int main(){
	FILE *file = fopen("file.csv", "r"); //baca file 
	if (file == NULL) {
    printf("Error opening file"); //kalau file eror 
    return 1;  
	}
	
	int choice; 
	property data[3945];
	int count = 0;
    char line[256];

	fgets(line, sizeof(line), file); 
	while (fgets(line, sizeof(line), file) != NULL && count < 3945){
	    sscanf(line, "%99[^,], %99[^,], %d, %d, %d, %d, %49[^,], %[^\n]",
	            data[count].location1, data[count].location2, &data[count].price,
	            &data[count].rooms, &data[count].bathrooms, &data[count].carParks,
	            data[count].type, data[count].furnish);
	        count++;
	}
    
    rewind(file); //buat baca dari atas lagi 
    fgets(line, sizeof(line), file);
    
    for (int i = 0; i < count; i++) {
        fscanf(file, "%99[^,], %99[^,], %d, %d, %d, %d, %49[^,], %[^\n]\n",
               data[i].location1, data[i].location2, &data[i].price, &data[i].rooms,
               &data[i].bathrooms, &data[i].carParks, data[i].type, data[i].furnish);
    }

    fclose(file);
	
	int sorted = 0; //nandain udh ke sorted apa belum (export data)
	
	do{	
		menu(); 
		scanf("%d", &choice); getchar(); 
		
		if (choice == 1){
			displaydata(data, count); 
			clear(); 
		}
		else if (choice == 2){
			searchdata(data, count); 
			clear(); 
		}
		else if (choice == 3){
			char column[20];
		    char order[10];
		
		    printf("Choose column (Location1, Location2, Price, Rooms, Bathrooms, CarParks, Type, Furnish): ");
		    scanf("%s", column);
			do {
		    	printf("Enter the order (asc or dsc): ");
		        scanf("%s", order);
		        if (strcmp(order, "asc") != 0 && strcmp(order, "dsc") != 0){
		            printf("Invalid! Please enter 'asc' or 'dsc'\n");
		        }
		    } while (strcmp(order, "asc") != 0 && strcmp(order, "dsc") != 0);
		
		    sortdata(data, count, column, order);
		    sorted = 1; //untuk nandain kalau udh ke sorted (untuk export data)
			clear(); 
		}
		else if (choice == 4){
			exportdata(); //export data biasa aja 
			//exportdata(data, count, sorted); //kalau mau export data yg udh ke sorted
			clear(); 
		}
		else if (choice == 5){
			printf("Goodbyeee...");
			clear(); 
		}
		else {
            printf("Invalid choice! Please try again!\n");
			clear();
		}
	}while (choice != 5); 
 
	return 0; 
}
