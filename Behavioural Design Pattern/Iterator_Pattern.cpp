#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class Song
{
public:
    string title;
    string artist;

    Song(string t, string a) : title(t), artist(a) {}
};

class Iterator
{
public:
    virtual bool hasNext() = 0;
    virtual Song next() = 0;
};

class IterableCollection
{
public:
    virtual Iterator *createIterator() = 0;
};

class PlaylistIterator : public Iterator
{
private:
    vector<Song> &songs;
    int index;

public:
    PlaylistIterator(vector<Song> &s) : songs(s), index(0) {}

    bool hasNext() override
    {
        return index < songs.size();
    }
    Song next() override
    {
        Song current = songs[index];

        // Print some info about the song being returned
        cout << "Returning song: " << current.title
             << " by " << current.artist << endl;

        index++;
        return current;
    }
};

class Playlist : public IterableCollection
{
private:
    vector<Song> songs;

public:
    void addSong(const Song &song)
    {
        songs.push_back(song);
    }
    Iterator *createIterator() override
    {
        return new PlaylistIterator(songs);
    }
};
int main()
{
    Playlist pl;
    Song s1("tum hi ho", "Arijit");
    Song s2("Haa tu hain", "KK");
    Song s3("Tere liye", "Atif");
    pl.addSong(s1);
    pl.addSong(s2);
    pl.addSong(s3);
    Iterator *it = pl.createIterator();
    while (it->hasNext())
    {
        it->next();
    }
    delete it;
}