let original_theme_active = true;

/**
 * Toggles between the original and alternative themes.
 *
 * When the original theme is active, this function enables the alternative theme by adding the "alternative" class
 * to the document's root element and updates the state flag accordingly. If the alternative theme is active, it removes
 * the class and resets the state to reflect that the original theme is in use.
 */
function toggle_alternative_theme() {
    if(original_theme_active) {
        document.documentElement.classList.add("alternative")
        original_theme_active = false;
    } else {
        document.documentElement.classList.remove("alternative")
        original_theme_active = true;
    }
}