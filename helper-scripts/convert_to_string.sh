#!/usr/bin/env bash
# AI-Disclaimer: This file was largely generated using AI and only tested for our
# specific use case. As such functionality can't be guaranteed.
#
BOLD=$'\033[1m'
RESET=$'\033[0m'

usage() {
  cat <<EOF
${BOLD}Usage: ./convert_ascii.sh input.txt [VARIABLE_NAME]${RESET}

Example:
  ./convert_ascii.sh ascii_art.txt MEDIUM_X

If ascii_art.txt contains:
  .___________. __   __  ___ .___________.    ___       __  ___ .___________.  ______    _______ 
  |           ||  | |  |/  / |           |   /   \     |  |/  / |           | /  __  \  |   ____|
  \`---|  |----\`|  | |  '  /  \`---|  |----\`  /  ^  \    |  '  /  \`---|  |----\`|  |  |  | |  |__    
      |  |     |  | |    <       |  |      /  /_\  \   |    <       |  |     |  |  |  | |   __|   
      |  |     |  | |  .  \      |  |     /  _____  \  |  .  \      |  |     |  \`--'  | |  |____  
      |__|     |__| |__|\__\     |__|    /__/     \__\ |__|\__\     |__|      \______/  |_______| 

The script outputs:

#define MEDIUM_X "\\
.___________. __   __  ___ .___________.    ___       __  ___ .___________.  ______    _______ \n\\
|           ||  | |  |/  / |           |   /   \\     |  |/  / |           | /  __  \\  |   ____| \n\\
\`---|  |----\`|  | |  '  /  \`---|  |----\`  /  ^  \\    |  '  /  \`---|  |----\`|  |  |  | |  |__   \\n\\
    |  |     |  | |    <       |  |      /  /_\\  \\   |    <       |  |     |  |  |  | |   __|   \n\\
    |  |     |  | |  .  \\      |  |     /  _____  \\  |  .  \\      |  |     |  \`--'  | |  |____  \n\\
    |__|     |__| |__|\\__\\     |__|    /__/     \\__\\ |__|\\__\\     |__|      \\______/  |_______| \n\\
"
EOF
}

if [ "$#" -lt 2 ]; then
    usage
    exit 1
fi

input_file="$1"
varname="$2"

# Begin output: note the backslash at the end of the first line for multi-line C string literal
echo "#define $varname \"\\"

# Process each line of the input file
while IFS= read -r line; do
    # Escape backslashes by replacing each '\' with '\\'
    escaped_line=$(echo "$line" | sed 's/\\/\\\\/g')
    # Also escape double quotes, if any
    escaped_line=$(echo "$escaped_line" | sed 's/"/\\"/g')
    # Print the line with an embedded newline escape and a continuation backslash
    echo "${escaped_line}\\n\\"
done < "$input_file"

# End the C variable declaration
echo "\""
