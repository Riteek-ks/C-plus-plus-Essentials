#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
// Base class for MediaItem
class MediaItem {
protected:
    string name;
    string dateCreated;
    int size;
 
public:
    MediaItem(string name, string dateCreated, int size) : name(name), dateCreated(dateCreated), size(size) {}
 
    virtual void display() const = 0; // Pure virtual function
    virtual void share() const = 0;    // Another responsibility: sharing
};
 
// Interface for sharable items
class Sharable {
public:
    virtual void share() const = 0;
};
 
// Image class representing an image media item
class Image : public MediaItem, public Sharable {
private:
    string format;
 
public:
    Image(string name, string dateCreated, int size, string format)
        : MediaItem(name, dateCreated, size), format(format) {}
 
    void display() const override {
        cout << "Image: " << name << ", Date Created: " << dateCreated << ", Size: " << size << ", Format: " << format << endl;
    }
 
    void share() const override {
        cout << "Sharing " << name << " via Bluetooth, WhatsApp, and Mailbox." << endl;
    }
};
 
// Video class representing a video media item
class Video : public MediaItem, public Sharable {
private:
    string format;
 
public:
    Video(string name, string dateCreated, int size, string format)
        : MediaItem(name, dateCreated, size), format(format) {}
 
    void display() const override {
        cout << "Video: " << name << ", Date Created: " << dateCreated << ", Size: " << size << ", Format: " << format << endl;
    }
 
    void share() const override {
        cout << "Sharing " << name << " via Bluetooth, WhatsApp, and Mailbox." << endl;
    }
};
 
// Gallery class to manage media items
class Gallery {
private:
    vector<MediaItem*> items;
 
public:
    void addMediaItem(MediaItem* item) {
        items.push_back(item);
    }
 
    void displayAll() const {
        cout << "Gallery Contents:" << endl;
        for (const MediaItem* item : items) {
            item->display();
        }
    }
 
    void shareAll() const {
        cout << "Sharing all media items:" << endl;
        for (const MediaItem* item : items) {
            item->share();
        }
    }
};
 
int main() {
    // Create some media items
    Image img1("Nature.jpg", "2024-05-07", 2048, "JPEG");
    Image img2("Sunset.png", "2024-05-07", 3072, "PNG");
    Video vid1("Vacation.mp4", "2024-05-06", 10240, "MP4");
 
    // Create a gallery and add media items
    Gallery gallery;
    gallery.addMediaItem(&img1);
    gallery.addMediaItem(&img2);
    gallery.addMediaItem(&vid1);
 
    // Display gallery contents
    gallery.displayAll();
 
    // Share all media items
    gallery.shareAll();
 
    return 0;
}