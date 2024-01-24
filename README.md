# BetterPTT

BetterPTT is a plugin for [EuroScope](https://www.euroscope.hu/wp/) that blocks key press events for the \` (US layout)
/ ^ (German layout) key to the EuroScope window. Allowing it to be used as a push-to-talk key.

## Functionality

Upon startup, the plugin determines the relevant key according to the current keyboard layout. It then installs a
keyboard event hook that exclusively intercepts events for this key. This interception is isolated to the EuroScope
window and does not interfere with other applications.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.