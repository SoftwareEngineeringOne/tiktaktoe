#!/usr/bin/env bash
# AI-Disclaimer: This file was largely generated using AI and only tested for our
# specific use case. As such functionality can't be guaranteed.

BOLD=$'\033[1m'
RESET=$'\033[0m'

usage() {
  cat <<EOF
${BOLD}Usage: ./convert_ascii.sh input.txt [ARRAY_NAME] [desired_width]${RESET}

Example:
  ./convert_ascii.sh ascii_art.txt MEDIUM_X 7

If ascii_art.txt contains:
  ╲ ╱  
   ╳   
  ╱ ╲  

Then the script outputs:
static char *MEDIUM_X[3][7] = {
    {" ", " ", DIAGONAL_BW, " ", DIAGONAL_FW, " ", " "},
    {" ", " ", " ", DIAGONAL_MID, " ", " ", " "},
    {" ", " ", DIAGONAL_FW, " ", DIAGONAL_BW, " ", " "},
};
EOF
}

if [ "$#" -lt 2 ]; then
    usage
    exit 1
fi

input_file="$1"
array_name="$2"

if [ "$#" -ge 3 ]; then
    desired_width="$3"
else
    # Get the length of the first line (remove newline)
    desired_width=$(head -n 1 "$input_file" | awk '{print length}')
fi

#  number of rows
rows=$(wc -l < "$input_file" | tr -d ' ')

echo "static char *${array_name}[${rows}][${desired_width}] = {"

# Use awk to process each line:
# 1. For each line, compute left/right padding to center the line in desired_width.
# 2. Convert each character to the corresponding token.
awk -v desired_width="$desired_width" '
# Function to generate a string with n spaces
function spaces(n) {
    s = ""
    for(i = 0; i < n; i++){
        s = s " "
    }
    return s
}
function convert(c) {
    if (c == "\\") {
        return "\"\\\\\""
    } 

    return "\"" c "\"";
}
{
    # Original line and its length.
    line = $0;
    line_length = length(line);
    # Calculate left and right padding to center the text.
    left_pad = int((desired_width - line_length) / 2);
    if (left_pad < 0) left_pad = 0;
    right_pad = desired_width - line_length - left_pad;
    # Construct the padded line.
    padded_line = spaces(left_pad) line spaces(right_pad);
    
    # Begin the C array row.
    printf "    {";
    # Process each character of the padded line.
    for(i = 1; i <= length(padded_line); i++){
        c = substr(padded_line, i, 1);
        printf (i == 1 ? "" : ", ");
        printf "%s", convert(c);
    }
    print "},";
}' "$input_file"

# Close the C array declaration.
echo "};"
