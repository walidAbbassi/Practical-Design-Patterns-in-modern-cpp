/*
* C++ Design Patterns: Composite
* Author: walid Abbassi [https://github.com/walidAbbassi]
* 2019
*
* Source code is licensed under MIT License
* (for more details see LICENSE)
*
*/

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm> 
#include <functional> 
#include <memory>

/*
* SongComponent  ==>  Component
* defines an interface for all objects in the composition
* both the composite and the leaf nodes
*/
class SongComponent {
public:

	virtual void addSong(const std::weak_ptr<SongComponent> &songComponent) { /* ... */ }

	virtual void displaySongInfo() const = 0;
	virtual std::string getName() const = 0;
	virtual ~SongComponent(){}
};

/*
* SongGroup  ==>  Composite
* defines behavior of the components having children
* and store child components
*/
class SongGroup : public SongComponent {
public:

	explicit SongGroup(const std::string &songGroupName) :songGroupName(songGroupName){}

	void addSong(const std::weak_ptr<SongComponent> &songComponent) override
	{
		if (!songComponent.expired())
		{
			children.push_back(songComponent);
		}
	}

	void displaySongInfo() const override
	{
		std::cout << " (";

		//for_each(children.begin(), children.end(), std::mem_fun(&SongComponent::displaySongInfo));  ==> old if you use raw pointer in your project		
		// or loop for range
		/*for (const auto& songComponent : children)
		{
			if (!songComponent.expired()) 
			{
				songComponent.lock()->displaySongInfo(); 
			}
		}*/
		for_each(children.begin(), children.end(), [=](std::weak_ptr<SongComponent> songComponent) {if (!songComponent.expired()) { songComponent.lock()->displaySongInfo(); } });

		std::cout << ") ";
	}

	std::string getName() const override { return songGroupName; }

	~SongGroup(){}

private:
	std::vector<std::weak_ptr<SongComponent>> children;
	std::string songGroupName;
};

/*
* Song  ==>  Leaf
* defines the behavior for the elements in the composition,
* it has no children
*/
class Song : public SongComponent {
public:
	explicit Song(const std::string &songName) : songName(songName) {}

	void displaySongInfo() const override
	{
		std::cout << "[" << songName << "]";
	}

	std::string getName() const override { return songName; }

	~Song(){}

private:
	std::string songName;
};


int main()
{
	std::shared_ptr<SongGroup> songGroupForSeason = std::make_shared<SongGroup>("Season");
	std::shared_ptr<SongGroup> songGroupForSpring = std::make_shared<SongGroup>("Spring");
	std::shared_ptr<SongGroup> songGroupForWinter = std::make_shared<SongGroup>("Winter");
	std::shared_ptr<Song> song_1 = std::make_shared<Song>("Song1");
	std::shared_ptr<Song> song_2 = std::make_shared<Song>("Song2");
	std::shared_ptr<Song> song_3 = std::make_shared<Song>("Song3");
	std::shared_ptr<Song> song_4 = std::make_shared<Song>("Song4");
	std::shared_ptr<Song> song_5 = std::make_shared<Song>("Song5");

	songGroupForSeason->addSong(song_1);				// ==> Season ( [Song1] )
	songGroupForSeason->addSong(songGroupForSpring);		// ==> Season ( [Song1] , Spring )

	songGroupForSpring->addSong(song_2);
	songGroupForSpring->addSong(song_3);				// ==> Spring ( [Song2][Song3] ) 
									// ==> Season( [Song1] , ([Song2][Song3]) )

	songGroupForWinter->addSong(song_4);
	songGroupForWinter->addSong(song_5);				// ==> Winter ( [Song4][Song5] )

	songGroupForSpring->addSong(songGroupForWinter);		// ==> Spring( [Song2][Song3] , Winter ) 
									// ==> Season( [Song1] , ([Song2][Song3] , ([Song4][Song5]) ) )

	std::cout << "songGroupForSeason : ";
	songGroupForSeason->displaySongInfo();
	std::cout << "\n";

	std::cout << "songGroupForSpring : ";
	songGroupForSpring->displaySongInfo();
	std::cout << "\n";

	std::cout << "songGroupForWinter : ";
	songGroupForWinter->displaySongInfo();
	std::cout << "\n";

	std::cout << "Song5 : ";
	song_5->displaySongInfo();
	std::cout << "\n";

	system("pause");
	return 0;
}
