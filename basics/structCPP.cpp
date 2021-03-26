#include <iostream>
#include <cstring>

using namespace std;

struct Books{

    char title[20];
    signed int pages;
    char author[20];
    int book_id;
};


void structure(Books *x){
    strcpy(x->title, "Book_title");
    strcpy(x->author, "Pidr");
    x->pages = 332445;
    x->book_id = 10;
    cout<<"Book's title: "<<x->title<<endl;
    cout<<"Book's author: "<<x->author<<endl;
    cout<<"Book's pages: "<<x->pages<<endl;
    cout<<"Books's id: "<<x->book_id<<endl;
}

int main(){

    
    Books book1;
    structure(&book1);
    return 0;
}

