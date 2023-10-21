#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<iomanip>
#include <cstring>

const int ALPHABET_SIZE = 26;

struct Node {
    Node* links[ALPHABET_SIZE]{};
    bool isEnd = false;
};

class Trie {
private:
    Node* root;

public:
    Trie() : root(new Node()) {}

    ~Trie() {
        
    }
    void destroyNodes(Node* node) {
    if (node == nullptr) {
        return;
    }

    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        destroyNodes(node->links[i]);
    }

    delete node;
}

    void insert(const std::string& word) {
        Node* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->links[index] == nullptr) {
                node->links[index] = new Node();
            }
            node = node->links[index];
        }
        node->isEnd = true;
    }

    bool search(const std::string& word) {
        Node* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->links[index] == nullptr) {
                return false;
            }
            node = node->links[index];
        }
        return node->isEnd;
    }

    void serialize(std::ofstream& outFile) {
        serializeHelper(root, outFile);
    }

    void deserialize(std::ifstream& inFile) {
        deserializeHelper(root, inFile);
    }

private:
    void serializeHelper(Node* node, std::ofstream& outFile) {
        if (node == nullptr) {
            outFile << "0"; // Write 0 for null node
            return;
        }

        outFile << "1"; // Write 1 for non-null node
        outFile << node->isEnd;

        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            serializeHelper(node->links[i], outFile);
        }
    }

    void deserializeHelper(Node*& node, std::ifstream& inFile) {
        char isNonNull;
        inFile >> isNonNull;

        if (isNonNull == '0') {
            node = nullptr;
            return;
        }

        node = new Node();
        inFile >> node->isEnd;

        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            deserializeHelper(node->links[i], inFile);
        }
    }
};
class Stock {
private:
    char name[20];
    float price;
    int quantity;
    int sold;

public:
    void get() {
        std::cout << "Enter name of the product followed by price and quantity: ";
        std::cin >> name >> price >> quantity;
        sold = 0;
    }

    void show() {
        std::cout << std::left << std::setw(20) << name << std::setw(10) << quantity << std::setw(10) << price << std::endl;
    }

    void withdraw(int qty) {
        if (quantity >= qty) {
            quantity -= qty;
            sold += qty;
            std::cout << "Stock updated." << std::endl;
            std::cout << "Total price to be paid: " << price * qty << std::endl;
        } else {
            std::cout << "Insufficient stock." << std::endl;
        }
    }

    void refill(int qty) {
        quantity += qty;
        std::cout << "Stock updated." << std::endl;
    }

    int stock_check(const char* nm) {
        
        return strcmp(nm, name);
    }

    int getQuantity() const {
        return quantity;
    }

    void sales_show() const {
        if (sold > 0) {
            std::cout << name << "\t\t\t" << sold << std::endl;
        }
    }
};

void display(std::ifstream& fin) {
    std::cout << "==================================================================" << std::endl;
    std::cout << "==============\tBadhon's Store\t==================" << std::endl;
    std::cout << "==================================================================" << std::endl;
    std::cout << "PRODUCTS_NAME\tSTOCK AVAILABLE\t\t\t PRICE" << std::endl;
    std::cout << "============================================================" << std::endl;

    Stock st;
    while (fin.read(reinterpret_cast<char*>(&st), sizeof(Stock))) {
        st.show();
    }
}
int main() {
    char choice;
    Stock st;

    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add new product" << std::endl;
        std::cout << "2. Display stock" << std::endl;
        std::cout << "3. Withdraw" << std::endl;
        std::cout << "4. Refill" << std::endl;
        std::cout << "5. Sales Report" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        std::ifstream fin("shop.dat", std::ios::binary);
        std::ofstream fout("shop.dat", std::ios::binary | std::ios::app);
        std::fstream fio("shop.dat", std::ios::binary | std::ios::in | std::ios::out);

        switch (choice) {
            case '1': {
                st.get();
                fout.write(reinterpret_cast<char*>(&st), sizeof(Stock));
                std::cout << "Item updated." << std::endl;
                break;
            }
            case '2': {
                display(fin);
                break;
            }
            case '3': {
                char temp[100];
                int qty;
                std::cout << "Enter the product's name: ";
                std::cin >> temp;
                std::cout << "Enter quantity: ";
                std::cin >> qty;
                long pos = 0;
                while (fio.read(reinterpret_cast<char*>(&st), sizeof(Stock))) {
                    pos = fio.tellg();
                    if (st.stock_check(temp) == 0) {
                        if (st.getQuantity() >= qty) {
                            st.withdraw(qty);
                            fio.seekp(pos);
                            fio.write(reinterpret_cast<char*>(&st), sizeof(Stock));
                            std::cout << "Record updated." << std::endl;
                        } else {
                            std::cout << "Insufficient stock." << std::endl;
                        }
                        break;
                    }
                }
                if (fio.eof()) {
                    std::cout << "Record not found." << std::endl;
                }
                break;
            }
            case '4': {
                char temp[100];
                int qty;
                std::cout << "Enter the product's name: ";
                std::cin >> temp;
                std::cout << "Enter quantity: ";
                std::cin >> qty;
                long pos = 0;
                while (fio.read(reinterpret_cast<char*>(&st), sizeof(Stock))) {
                    pos = fio.tellg();
                    if (st.stock_check(temp) == 0) {
                        st.refill(qty);
                        fio.seekp(pos);
                        fio.write(reinterpret_cast<char*>(&st), sizeof(Stock));
                        std::cout << "Record updated." << std::endl;
                        break;
                    }
                }
                if (fio.eof()) {
                    std::cout << "Record not found." << std::endl;
                }
                break;
            }
            case '5': {
                std::cout << "Sales Report:" << std::endl;
                st.sales_show();
                break;
            }
            case '6': {
                std::cout << "Exiting program." << std::endl;
                fin.close();
                fout.close();
                fio.close();
                return 0;
            }
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}
