#include <iostream>
#include <string>
#include <fstream>

using namespace std;
#define MAP_SIZE 51
#define ASCII_CHARS 128
#define MAX_CLASS_NAME_LENGTH 10


string symbol_to_html_class (char symbol) 
{
     switch (symbol){
     case '*' : return "bullet"; break;
     case '#' : return "wall"; break;
     case '.' : return "empty"; break;
     case '1' : return "tank1"; break;
     case '2' : return "tank2"; break;
     case 'D' : return "dead"; break;
     case 'G' : return "gold"; break;
     }
}

int main() 
{
     ifstream infile;
     ifstream map;
     map.open("backup_map.txt");
     char letter;
     cout << "<html><head>" << endl;
     cout << "<style type='text/css'>\n\
    .wall {width: 10px; height: 10px; background: none repeat scroll 0% 0% #282B1F; margin: 0pt; padding: 0pt; float: left;}\n\
    .empty {-moz-border-radius:5px; -webkit-border-radius:5px; width: 10px; height: 10px; background: none repeat scroll 0% 0% none; margin: 0pt; padding: 0pt; float: left;}\n\
    .tank1 {-moz-border-radius:3px; -webkit-border-radius:3px; width: 10px; height: 10px; background: none repeat scroll 0% 0% green; margin: 0pt; padding: 0pt; float: left;}\n\
    .tank2 {-moz-border-radius:3px; -webkit-border-radius:3px; width: 10px; height: 10px; background: none repeat scroll 0% 0% blue; margin: 0pt; padding: 0pt; float: left;}\n\
    .bullet {-moz-border-radius:5px; -webkit-border-radius:5px; width:  5px; height:  5px; background: none repeat scroll 0% 0% black; margin: 2.5px; padding: 0pt; float: left;}\n\
    .gold {-moz-border-radius:5px; -webkit-border-radius:5px; width: 8px; height: 8px; background: none repeat scroll 0% 0% goldenRod; margin: 0pt; padding: 0pt; float: left; border-style: solid; border-width:1px;}\n\
    .dead {-moz-border-radius:5px; -webkit-border-radius:5px; width: 10px; height: 10px; background: none repeat scroll 0% 0% red; margin: 0pt; padding: 0pt; float: left;}\n\
</style>" << endl;
     cout << "</head><body onload = update_map_0()>" << endl;
     cout << "<div style='width: 500px; height: 500px; margin: 0pt; padding: 0pt; border: 0pt none; background: none repeat scroll 0% 0% #E7ECD6;' id='divboard'>" << endl;
     for (int i = 0; i < MAP_SIZE - 1; i++){
          for (int j = 0; j < MAP_SIZE - 1; j++){
               map >> letter;
               // cout << letter;
               cout << "    <div id = '"<< i << "q" << j << "' class = '" << symbol_to_html_class(letter) << "'></div>" << endl;
          }
          // cout << endl;
     }
     cout << "</div>" << endl;
     cout << "<span> Player one (green) score : <div id = 'player1_score'>foo</div> </span>" << endl;
     cout << "<span> Player one (green) score : <div id = 'player2_score'>foo</div> </span>" << endl;
     infile.open("foobar");
     int x, y, i = 0;
     char k;
     cout << "<script type='text/javascript'>" << endl;
     cout << "var pause = false;" << endl;
     cout << "var update_map = {};" << endl;
     cout << "var char_to_color_table = {}; \n\
              char_to_color_table['.'] = 'empty'; \n\
              char_to_color_table['#'] = 'wall'; \n\
              char_to_color_table['G'] = 'gold'; \n\
              char_to_color_table['D'] = 'dead'; \n\
              char_to_color_table['2'] = 'tank2'; \n\
              char_to_color_table['1'] = 'tank1'; \n\
              char_to_color_table['*'] = 'bullet';" << endl;
     cout << "function update_map_" << i << "(pause) {" << endl;
     cout << "if ( ! pause ) {" << endl;
     do {
          infile >> x >> y >> k;
          if (k != 'F') {
               cout << "    document.getElementById('" << x << "q" << y << "').className = char_to_color_table['" << k << "'];" << endl;
          }
          else {
               cout <<"     document.getElementById('player1_score').innerHTML = '" << x << "';" << endl;
               cout <<"     document.getElementById('player2_score').innerHTML = '" << y << "';" << endl;
               i++;
               cout << "    var t= setTimeout('update_map_" << i << "(pause)', 1);" << endl;
               cout << "    }" << endl;
               cout << "}" << endl;
               cout << "function update_map_" << i << "(pause) {" << endl;
               cout << "    if ( ! pause ) {" << endl;
          }
     }
     while ( not infile.eof() );
     cout << "    }" << endl;
     cout << "}" << endl;
     while ( i >= 0 ) {
          cout << "func_array[" << i << "] = update_map_0;" << endl;
          i--;
     }
     cout << "function pause_game() {" << endl;
     cout << "    pause = ! pause;" << endl;
     cout << "}" << endl;
     cout << "</script><button onclick =pause_game()>Pause</button></body></html>" << endl;
     return 0;
}
