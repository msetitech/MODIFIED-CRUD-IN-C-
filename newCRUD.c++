#include<iostream>
#include<string>
#include<vector>
using namespace std;


// starting Item
struct Item{
    string name;
    int id;
    float price;
    
    void displayItem() const{
        cout << "\nProduct Id   : " << id<<endl;
        cout << "Product Name   : "<< name <<endl;
        cout << "Product Price  : "<< price<< endl;
    }
};

void createItem(vector<Item>&items);
void readItem(const vector<Item>&items);
void updateItem(vector<Item>&items);
void deleteItem(vector<Item>&items);

int main(){
    vector<Item>items;
    int choice;
    
    do{
        cout << "\n\n----Product Managment System---- \n";
        cout << "\n1. Create Product";
        cout << "\n2. Read Product";
        cout << "\n3. Update Product";
        cout << "\n4. Delete Product";
        cout << "\n5. Exit Stsyem";
        cout << "\n \n----------------------------------\n";
        cout << "\nEnter Your CHoice: ";
        cin >> choice;
        cout << "\n----------------------------------\n";
        
        switch(choice){
            case 1:
            createItem(items);
            break;
            
            case 2:
            readItem(items);
            break;
            
            case 3:
            updateItem(items);
            break;
            
            case 4:
            deleteItem(items);
            break;
            
            case 5:
            cout << "Exiting Project ..... ";
            break;
            default:
            cout << "Incorect Choice Try Again 1- 4: ";
            break;
        }
    }while(choice != 4);
    return 0;
}

void createItem(vector<Item>&items){
    Item newItem;
    cout << "ENTER PRODUCT DETAILS TO CREATE PRODUCT \n\n";
    cout << "Enter Product ID   : ";
    cin >> newItem.id;
    cin.ignore();
    cout << "Enter Product Name : ";
    getline(cin, newItem.name);
    cout << "Product Price      : ";
    cin >> newItem.price;
    
    items.push_back(newItem);
    cout << "Product Created Successfully";
}

void readItem(const vector<Item>&items){
    if(items.empty()){
        cout << "No Product Found in Store";
    }else{
        cout << "----Item List Bellow ----";
        for(const auto & item:items){
            
            item.displayItem();
        }
        cout << "--------------------------";
    }
}

void updateItem(vector<Item>&items){
    int id;
    cout << "To Update Product Enter ID : ";
    cin >> id;
    

    
    for(auto & item:items){
        if(item.id == id){
            cin.ignore();
            cout << "Update Product Name     : ";
            getline(cin, item.name);
            cout << "Update Product Price    : ";
            cin >> item.price;
            cout << "Item Updated Successfull ";
            return;
        }
    }
    cout << "Item With ID :" << id << " is not found on store \n";
}

void deleteItem(vector<Item>&items){
     if(items.empty()){
        cout << "No iTem To delete";
        return;
    }
    
    int id;
    cin >> id;
    
    for(auto it = items.begin(); it !=items.end();++it){
        if(it -> id == id){
            items.erase(it);
            cout<< "Item Deleted SUccessful";
            return;
        }
    }
    cout << "Item with ID "<< id <<" is not found";
}
