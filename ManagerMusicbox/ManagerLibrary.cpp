#include<bits/stdc++.h>
using namespace std;
class MediaItem {
    protected: 
    string title;
    int duration ; 
    public  :
    MediaItem(string t, int d) : title(t), duration(d) {}
    virtual void play() {
        cout << "Playing: " << title << " (" << duration << "s)" << endl;
    }
    virtual string getInfo() {
        return "Title: " + title + ", Duration: " + to_string(duration) + "s";
    }
    virtual ~MediaItem() {
        cout<<"Media destructor has been called"<<endl;
    }
};
// Derived class: Track
class Track : public MediaItem {
private:
    string artist;
    string genre;
public:
    Track(string t, int d, string a, string g): MediaItem(t, d), artist(a), genre(g) {}

    void play() override {
        cout << " Now playing track: " << title << " by " << artist << " [" << genre << "]" << endl;
    }

    string getInfo() override {
        return "Track: " + title + ", Artist: " + artist + ", Genre: " + genre + ", Duration: " + to_string(duration) + "s";
    }
};

// Derived class: PodcastEpisode
class PodcastEpisode : public MediaItem {
private:
    string host;
    string seriesName;
public:
    PodcastEpisode(string t, int d, string h, string s): MediaItem(t, d), host(h), seriesName(s) {}

    void play() override {
        cout << " Listening to podcast: " << title << " from series '" << seriesName << "' hosted by " << host << endl;
    }

    string getInfo() override {
        return "Podcast: " + title + ", Series: " + seriesName + ", Host: " + host + ", Duration: " + to_string(duration) + "s";
    }
};
class Playlist{
    private:
    string name; 
    vector<MediaItem*>items;
    public: 
    Playlist(string n ): name(n){};
    void addIteam(MediaItem* item){
        items.push_back(item);
    }
    void playAll() {
        cout << " Playing playlist: " << name << endl;
        for (auto item : items) {
            item->play();
        }
    }

    void showAll() {
        cout << " Playlist: " << name << " contains:" << endl;
        for (auto item : items) {
            cout << "- " << item->getInfo() << endl;
        }
    }
    ~Playlist() {
        for (auto item : items) {
            delete item;
        }
        cout<<"Playlist "<<name<<" has been cleared !\n";
    }
};
class Users{
    public:
    string name ; 
    vector<Playlist>
    class:
    Users(string n_user):name(n_user){}; 

};



int main(){
    vector<MediaItem>v;


}