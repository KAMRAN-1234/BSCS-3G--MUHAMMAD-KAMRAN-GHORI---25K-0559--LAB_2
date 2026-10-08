#include <iostream>

class PlaylistManager {
private:
    int** playlists;
    int* playlistSizes;
    int playlistCount;

public:
    PlaylistManager(int count) {
        playlistCount = count;
        playlists = new int*[playlistCount];
        playlistSizes = new int[playlistCount];

        for (int playlistIndex = 0; playlistIndex < playlistCount; ++playlistIndex) {
            std::cout << "Enter number of tracks in playlist " << playlistIndex << ": ";
            std::cin >> playlistSizes[playlistIndex];

            playlists[playlistIndex] = new int[playlistSizes[playlistIndex]];
            std::cout << "Enter track IDs: ";
            for (int trackIndex = 0; trackIndex < playlistSizes[playlistIndex]; ++trackIndex) {
                std::cin >> playlists[playlistIndex][trackIndex];
            }
        }
    }

    PlaylistManager(const PlaylistManager& other) {
        playlistCount = other.playlistCount;
        playlists = new int*[playlistCount];
        playlistSizes = new int[playlistCount];

        for (int playlistIndex = 0; playlistIndex < playlistCount; ++playlistIndex) {
            playlistSizes[playlistIndex] = other.playlistSizes[playlistIndex];
            playlists[playlistIndex] = new int[playlistSizes[playlistIndex]];

            for (int trackIndex = 0; trackIndex < playlistSizes[playlistIndex]; ++trackIndex) {
                playlists[playlistIndex][trackIndex] = other.playlists[playlistIndex][trackIndex];
            }
        }

        std::cout << "Deep copy created successfully!\n";
    }

    void addTrack(int playlistIndex, int trackId) {
        if (playlistIndex < 0 || playlistIndex >= playlistCount) {
            std::cout << "Invalid playlist!\n";
            return;
        }

        int oldSize = playlistSizes[playlistIndex];
        int* updatedPlaylist = new int[oldSize + 1];

        for (int index = 0; index < oldSize; ++index) {
            updatedPlaylist[index] = playlists[playlistIndex][index];
        }

        updatedPlaylist[oldSize] = trackId;
        delete[] playlists[playlistIndex];
        playlists[playlistIndex] = updatedPlaylist;
        ++playlistSizes[playlistIndex];

        std::cout << "Track added successfully!\n";
    }

    void play(int playlistIndex, int trackIndex) {
        if (playlistIndex < 0 || playlistIndex >= playlistCount) {
            std::cout << "Invalid playlist!\n";
            return;
        }
        if (trackIndex < 0 || trackIndex >= playlistSizes[playlistIndex]) {
            std::cout << "Invalid track!\n";
            return;
        }

        std::cout << "Playing track ID: " << playlists[playlistIndex][trackIndex] << std::endl;
    }

    void show() const {
        for (int playlistIndex = 0; playlistIndex < playlistCount; ++playlistIndex) {
            std::cout << "Playlist " << playlistIndex << ": ";
            for (int trackIndex = 0; trackIndex < playlistSizes[playlistIndex]; ++trackIndex) {
                std::cout << playlists[playlistIndex][trackIndex] << ' ';
            }
            std::cout << std::endl;
        }
    }

    ~PlaylistManager() {
        for (int playlistIndex = 0; playlistIndex < playlistCount; ++playlistIndex) {
            delete[] playlists[playlistIndex];
        }
        delete[] playlists;
        delete[] playlistSizes;
    }
};

int main() {
    int playlistCount;
    std::cout << "Enter number of playlists: ";
    std::cin >> playlistCount;

    PlaylistManager original(playlistCount);
    std::cout << "\nOriginal playlists:\n";
    original.show();

    PlaylistManager copy = original;
    std::cout << "\nCopied playlists:\n";
    copy.show();

    int playlistIndex;
    int trackId;
    std::cout << "\nEnter playlist to add track to copy: ";
    std::cin >> playlistIndex;
    std::cout << "Enter track ID: ";
    std::cin >> trackId;

    copy.addTrack(playlistIndex, trackId);

    std::cout << "\nOriginal after modifying copy:\n";
    original.show();
    std::cout << "\nCopy after modification:\n";
    copy.show();

    std::cout << "\nTesting track access:\n";
    copy.play(0, 0);

    return 0;
}