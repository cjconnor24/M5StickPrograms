# Simple Meeting Indicator

This is a really simple POC of using an M5StickC Plus as a meeting indicator. I use this in conjunction with a StreamDeck.

As this is a POC, there is not error handling etc. - will probably have some pretty buggy behaviour.

### Demo

Simple POC demo can be seen [here](https://www.tiktok.com/@cjconnor24/video/7189377546981543174?is_from_webapp=1&sender_device=pc&web_id=7194562283862918662).
## Usage

To trigger the state change on the M5StickC, simply send a get request with desired status.

### Busy
```
curl http://[thestickipaddress]?status=busy
```
### Free
```
curl http://[thestickipaddress]?status=clear
```

