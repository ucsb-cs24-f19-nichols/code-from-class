#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;


// This class represents either a single lyric of a song
// or a pause of a certain duration. type must be either equal
// to "LYRIC" or "PAUSE". If the type is "LYRIC", then 
// pauseDuration does not need to be initialized, and vice versa.
class LyricOrPause {
public:
    // two different constructors: if we use the first,
    // it holds a lyric; if we use the second, it holds
    // a pause
    LyricOrPause(string lyric);
    LyricOrPause(double pauseDuration);
    // the following three functions don't *change* any of the member
    // variables, so they get the const suffix. The compiler enforces
    // this rule and doesn't compile if we accidentally change something
    // inside these functions.
    string getType() const;
    string getLyric() const;
    double getPauseDuration() const;
private:
    string type;
    string lyric;
    double pauseDuration;
};

string LyricOrPause::getType() const { return type; }
string LyricOrPause::getLyric() const { return lyric; }
double LyricOrPause::getPauseDuration() const { return pauseDuration; }

// every object has a this variable that points to the current object
LyricOrPause::LyricOrPause(string lyric) {
    this->lyric = lyric;
    type = "LYRIC";
}

// alternative constructor: using an initialization list; the body is empty
// because there's nothing else to do
LyricOrPause::LyricOrPause(double pauseDuration) : 
    type("PAUSE"), pauseDuration(pauseDuration) {}

// A Song holds a bunch of lyrics. We do not allow the user
// of the Song class to touch the underlying vector--they must
// to through the addLyricOrPause function.
class Song {
public:
    // Adds a single LyricOrPause to the current song that we're building
    void addLyricOrPause(LyricOrPause p);
    // the getLyrics function returns a constant reference to the vector,
    // which means the vector cannot be changed. The function changes no
    // member variables, so it also gets the const suffix.
    const vector<LyricOrPause>& getLyrics() const;
private:
    // a vector is a data type defined the C++ standard library; it
    // acts like an array
    vector<LyricOrPause> v;
};

void Song::addLyricOrPause(LyricOrPause p) {
    v.push_back(p);
}

const vector<LyricOrPause>& Song::getLyrics() const {
    return v;
}

class Karaoke {
public:
    void loadSong(Song s);
    void playLoadedSong();
private:
    // the pause function is just for us; the users of the Karaoke class
    // cannot call it
    void pause(double duration);
    // This is the song that we're loading into our karaoke machine
    Song song;
};

void Karaoke::loadSong(Song s) {
    song = s;
}

// you are not required to understand how to implement the following function;
// I had to look it up too lol
// Stops program execution for `duration` seconds.
void Karaoke::pause(double duration) {
    std::this_thread::sleep_for(std::chrono::microseconds(static_cast<int>(1e6 * duration)));
}

void Karaoke::playLoadedSong() {
    // countdown for 5 seconds to give us enough time to press play
    cout << "Starting in 5..." << endl;
    pause(1);
    cout << "4..." << endl;
    pause(1);
    cout << "3..." << endl;
    pause(1);
    cout << "2..." << endl;
    pause(1);
    cout << "1..." << endl;
    pause(1);
    cout << "Starting now!" << endl << endl;

    // iterate through the lyrics
    const vector<LyricOrPause> &lyrics = song.getLyrics();
    for (int i = 0; i < lyrics.size(); i++) {
        if (lyrics[i].getType() == "LYRIC") {
            cout << lyrics[i].getLyric() << endl;
        } else if (lyrics[i].getType() == "PAUSE") {
            pause(lyrics[i].getPauseDuration());
        } else {
            // impossible to get here thanks to the magic of 
            // constructors and access specifiers!
            assert(false); 
        }
    }
}

int main(int argc, char const *argv[])
{
    Karaoke k;
    Song s;

    s.addLyricOrPause(LyricOrPause(6.86));
    s.addLyricOrPause(LyricOrPause("Why men great 'til they gotta be great?"));
    s.addLyricOrPause(LyricOrPause(3.5));
    s.addLyricOrPause(LyricOrPause(0.34));
    s.addLyricOrPause(LyricOrPause("Woo"));
    s.addLyricOrPause(LyricOrPause(0.5));
    s.addLyricOrPause(LyricOrPause(0.48));
    s.addLyricOrPause(LyricOrPause("I just took a DNA test, turns out I'm 100%"));
    s.addLyricOrPause(LyricOrPause(3.96));
    s.addLyricOrPause(LyricOrPause(0.24));
    s.addLyricOrPause(LyricOrPause("that *****"));
    s.addLyricOrPause(LyricOrPause(0.76));
    s.addLyricOrPause(LyricOrPause("Even when I'm crying crazy"));
    s.addLyricOrPause(LyricOrPause(1.46));
    s.addLyricOrPause(LyricOrPause("Yeah, I got boy problems, that's the human\nin me"));
    s.addLyricOrPause(LyricOrPause(3.26));
    s.addLyricOrPause(LyricOrPause("Bling bling, then I solve 'em, that's the\ngoddess in me"));
    s.addLyricOrPause(LyricOrPause(2.74));
    s.addLyricOrPause(LyricOrPause("You coulda had a bad *****, non-committal"));
    s.addLyricOrPause(LyricOrPause(2.68));
    s.addLyricOrPause(LyricOrPause("Help you with your career just a little"));
    s.addLyricOrPause(LyricOrPause(3.24));
    s.addLyricOrPause(LyricOrPause(0.009));
    s.addLyricOrPause(LyricOrPause("You're 'posed to hold me down, but you're\nholding me back"));
    s.addLyricOrPause(LyricOrPause(3.521));
    s.addLyricOrPause(LyricOrPause("And that's the sound of me not calling you\nback"));
    s.addLyricOrPause(LyricOrPause(4.09));
    s.addLyricOrPause(LyricOrPause("Why men great 'til they gotta be great?"));
    s.addLyricOrPause(LyricOrPause(2.939));
    s.addLyricOrPause(LyricOrPause("Don't text me, tell it straight to my face"));
    s.addLyricOrPause(LyricOrPause(2.921));
    s.addLyricOrPause(LyricOrPause("Best friend sat me down in the salon chair"));
    s.addLyricOrPause(LyricOrPause(3.12));
    s.addLyricOrPause(LyricOrPause("Shampoo press, get you out of my hair"));
    s.addLyricOrPause(LyricOrPause(2.68));
    s.addLyricOrPause(LyricOrPause("Fresh photos with the bomb lighting"));
    s.addLyricOrPause(LyricOrPause(2.939));
    s.addLyricOrPause(LyricOrPause(0.001));
    s.addLyricOrPause(LyricOrPause("New man on the Minnesota Vikings"));
    s.addLyricOrPause(LyricOrPause(3.22));
    s.addLyricOrPause(LyricOrPause("Truth hurts, needed something more exciting"));
    s.addLyricOrPause(LyricOrPause(2.5));
    s.addLyricOrPause(LyricOrPause("Bom bom bi dom bi dum bum bay"));
    s.addLyricOrPause(LyricOrPause(3.0));
    s.addLyricOrPause(LyricOrPause("You tried to break my heart?"));
    s.addLyricOrPause(LyricOrPause(1.28));
    s.addLyricOrPause(LyricOrPause("Oh, that breaks my heart"));
    s.addLyricOrPause(LyricOrPause(1.68));
    s.addLyricOrPause(LyricOrPause("That you thought you ever had it"));
    s.addLyricOrPause(LyricOrPause(1.68));
    s.addLyricOrPause(LyricOrPause("No, you ain't from the start"));
    s.addLyricOrPause(LyricOrPause(1.26));
    s.addLyricOrPause(LyricOrPause("Hey, I'm glad you're back with your *****"));
    s.addLyricOrPause(LyricOrPause(1.84));
    s.addLyricOrPause(LyricOrPause(0.01));
    s.addLyricOrPause(LyricOrPause("I mean who would wanna hide this?"));
    s.addLyricOrPause(LyricOrPause(1.65));
    s.addLyricOrPause(LyricOrPause("I will never, ever, ever, ever, ever be your\nside chick"));
    s.addLyricOrPause(LyricOrPause(2.84));
    s.addLyricOrPause(LyricOrPause("I put the sing in single"));
    s.addLyricOrPause(LyricOrPause(1.9));
    s.addLyricOrPause(LyricOrPause(0.2));
    s.addLyricOrPause(LyricOrPause("Ain't worried 'bout a ring on my finger"));
    s.addLyricOrPause(LyricOrPause(2.82));
    s.addLyricOrPause(LyricOrPause("So you can tell your friend, \"shoot your shot\"\nwhen you see 'em"));
    s.addLyricOrPause(LyricOrPause(4.56));
    s.addLyricOrPause(LyricOrPause("It's OK, he already in my DMs"));
    s.addLyricOrPause(LyricOrPause(3.12));
    s.addLyricOrPause(LyricOrPause("Why men great 'til they gotta be great?"));
    s.addLyricOrPause(LyricOrPause(3.12));
    s.addLyricOrPause(LyricOrPause("Don't text me, tell it straight to my face"));
    s.addLyricOrPause(LyricOrPause(3.16));
    s.addLyricOrPause(LyricOrPause("Best friend sat me down in the salon chair"));
    s.addLyricOrPause(LyricOrPause(2.96));
    s.addLyricOrPause(LyricOrPause("Shampoo press, get you out of my hair"));
    s.addLyricOrPause(LyricOrPause(2.96));
    s.addLyricOrPause(LyricOrPause("Fresh photos with the bomb lighting"));
    s.addLyricOrPause(LyricOrPause(2.82));
    s.addLyricOrPause(LyricOrPause("New man on the Minnesota Vikings"));
    s.addLyricOrPause(LyricOrPause(3.12));
    s.addLyricOrPause(LyricOrPause("Truth hurts, needed something more exciting"));
    s.addLyricOrPause(LyricOrPause(2.9));
    s.addLyricOrPause(LyricOrPause("Bom bom bi bom bi dum bum bay"));
    s.addLyricOrPause(LyricOrPause(3.04));
    s.addLyricOrPause(LyricOrPause("I'ma hit you back in a minute"));
    s.addLyricOrPause(LyricOrPause(3.0));
    s.addLyricOrPause(LyricOrPause("I don't play tag, *****, I been it"));
    s.addLyricOrPause(LyricOrPause(2.88));
    s.addLyricOrPause(LyricOrPause("We don't **** with lies, we don't do goodbyes"));
    s.addLyricOrPause(LyricOrPause(3.0));
    s.addLyricOrPause(LyricOrPause("We just keep it pushing like aye yi yi"));
    s.addLyricOrPause(LyricOrPause(3.28));
    s.addLyricOrPause(LyricOrPause("I'ma hit you back in a minute"));
    s.addLyricOrPause(LyricOrPause(3.0));
    s.addLyricOrPause(LyricOrPause("I don't play tag, *****, I been it"));
    s.addLyricOrPause(LyricOrPause(2.94));
    s.addLyricOrPause(LyricOrPause("We don't **** with lies, we don't do goodbyes"));
    s.addLyricOrPause(LyricOrPause(3.56));
    s.addLyricOrPause(LyricOrPause("We just keep it pushing like aye yi yi"));
    s.addLyricOrPause(LyricOrPause(2.98));
    s.addLyricOrPause(LyricOrPause("Why men great 'til they gotta be great?"));
    s.addLyricOrPause(LyricOrPause(3.12));
    s.addLyricOrPause(LyricOrPause(0.01));
    s.addLyricOrPause(LyricOrPause("Don't text me, tell it straight to my face"));
    s.addLyricOrPause(LyricOrPause(2.95));
    s.addLyricOrPause(LyricOrPause("Best friend sat me down in the salon chair"));
    s.addLyricOrPause(LyricOrPause(3.2));
    s.addLyricOrPause(LyricOrPause("Shampoo press, get you out of my hair"));
    s.addLyricOrPause(LyricOrPause(2.88));
    s.addLyricOrPause(LyricOrPause("Fresh photos with the bomb lighting"));
    s.addLyricOrPause(LyricOrPause(3.54));
    s.addLyricOrPause(LyricOrPause("New man on the Minnesota Vikings"));
    s.addLyricOrPause(LyricOrPause(2.38));
    s.addLyricOrPause(LyricOrPause("Truth hurts, needed something more exciting"));
    s.addLyricOrPause(LyricOrPause(2.88));
    s.addLyricOrPause(LyricOrPause("Bom bom bi bom bi dum bum bay"));
    s.addLyricOrPause(LyricOrPause(3.1));
    s.addLyricOrPause(LyricOrPause(1.9));
    s.addLyricOrPause(LyricOrPause("With the bomb lightinggggg"));
    s.addLyricOrPause(LyricOrPause(3.24));
    s.addLyricOrPause(LyricOrPause("Minnesota Vikingssssss"));
    s.addLyricOrPause(LyricOrPause(2.32));
    s.addLyricOrPause(LyricOrPause("ahhh eeeee"));
    s.addLyricOrPause(LyricOrPause(2.44));
    s.addLyricOrPause(LyricOrPause("yeee-ahhh-eah-ah-ah"));
    s.addLyricOrPause(LyricOrPause(2.48));

    k.loadSong(s);
    k.playLoadedSong();

    return 0;
}