#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Browser {
private:
    stack<string> historyBack;
    stack<string> historyForward;
    string currentUrl;

public:
    Browser(string homepage){
        currentUrl = homepage;
    }

    void visit(string url){
        historyBack.push(currentUrl);

        currentUrl = url;

        while (!historyForward.empty()){
            historyForward.pop();
        }
        cout << "Visited " << currentUrl << endl;
    }

    void back(){
        if(historyBack.empty()){
            cout << "ERROR ~ No history to go back" << endl;
            return;
        }

        historyForward.push(currentUrl);
        cout << "Went back to: " << currentUrl << endl;
    }

    void forward(){
        if (historyForward.empty()){
            cout << "ERROR ~ No forward history" << endl;
            return;
        }

        historyBack.push(currentUrl);

        currentUrl = historyForward.top();
        historyForward.pop();

        cout << "Went Forward to: " << currentUrl << endl;
    }
        void showCurrentPage() {
            cout << "Current Page: [" << currentUrl << "]" << endl;
    }

};

int main(){
    Browser chrome("google.com");
    
    // User browsing session
    
    chrome.visit("youtube.com");
    chrome.visit("github.com");
    chrome.visit("stackoverflow.com");

    cout << "\n--- Testing Back Button ---" << endl;
    chrome.back(); // Should go to github.com
    chrome.back(); // Should go to youtube.com

    cout << "\n--- Testing Forward Button ---" << endl;
    chrome.forward(); // Should go back to github.com

    cout << "\n--- Testing New Path (Breaking Forward History) ---" << endl;
    // We are at github.com. If we visit a NEW page now, 
    // stackoverflow.com (which was next) should be lost forever.
    chrome.visit("reddit.com"); 

    cout << "\n--- Attempting Forward ---" << endl;
    chrome.forward(); // Should fail because we started a new path

    return 0;
}
