//Asım Batuhan Demir -- 200101023

#include <stdlib.h>
#include <stdio.h>

// Düğüm yapısı tanımlanır
struct n {
    int x;
    struct n *next;
};

typedef struct n node; // 'struct n' tipini 'node' olarak yeniden adlandırılır

// Düğümleri ekrana bastıran fonksiyon
void display(node *r) {
    while (r != NULL) { // Düğüm NULL olana kadar döngü devam eder
        printf("%d\n", r->x); // Düğümün içindeki değeri ekrana yazdırır
        r = r->next; // Bir sonraki düğüme geçer
    }
}

// Listenin başına yeni bir düğüm ekleyen fonksiyon
void insert_at_beggining(node **head, int x) {
    node *new_node = (node *)malloc(sizeof(node)); // Yeni bir düğüm oluşturulur
    new_node->x = x; // Yeni düğümün içindeki değeri atanır
    new_node->next = *head; // Yeni düğümün bir sonraki işaretçisi, mevcut başlangıç düğümünü gösterir
    *head = new_node; // Yeni düğümü başlangıç düğümü olarak ayarlanır
}

// Listenin herhangi bir yerine yeni bir düğüm ekleyen fonksiyon
void insert_at_middle(node *r, int x, int position) {
    int count = 1;

    while (r != NULL && count < position - 1) { // Belirtilen pozisyona kadar veya listenin sonuna kadar ilerle
        r = r->next;
        count++;
    }

    if (r == NULL) { // Eğer pozisyon geçerli değilse
        printf("Invalid position.\n");
        return;
    }

    node *new_node = (node *)malloc(sizeof(node)); // Yeni bir düğüm oluştur
    new_node->x = x; // Yeni düğümün içindeki değeri atanır
    new_node->next = r->next; // Yeni düğümün bir sonraki işaretçisi, mevcut pozisyondaki düğümün bir sonraki düğümünü gösterir
    r->next = new_node; // Mevcut pozisyondaki düğümün bir sonraki işaretçisi, yeni düğümü gösterir
}

int main() {
    node *head;
    head = (node *)malloc(sizeof(node)); // Başlangıç düğümü oluşturuluyor

    printf("Enter the value for the head node: ");
    scanf("%d", &(head->x)); // Kullanıcıdan başlangıç düğüm değeri alınıyor

    head->next = NULL; // Başlangıç düğümünün bir sonraki düğümü NULL olarak ayarlanır

    int choice, value, position;

    do {
        // Kullanıcıya hangi işlemi yapmak istediğini sor
        printf("\nMenu:\n");
        printf("1. Add a node to the beginning of the list\n");
        printf("2. Add a node to a specific position in the list\n");
        printf("3. Print the values in the list\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Listenin başına düğüm ekleyen fonksiyonu çağır
                printf("Enter a value to add to the beginning of the list: ");
                scanf("%d", &value);
                insert_at_beggining(&head, value);
                break;
            case 2:
                // Listenin herhangi bir yerine düğüm ekleyen fonksiyonu çağır
                printf("Enter a value to add to the list: ");
                scanf("%d", &value);
                printf("Enter the position to add the node: ");
                scanf("%d", &position);
                insert_at_middle(head, value, position);
                break;
            case 3:
                // Listenin içindeki değerleri ekrana bastır
                printf("The values in the list are:\n");
                display(head);
                break;
            case 4:
                // Programdan çık
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}
