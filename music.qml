Item {
    height: 360
    width: 640

    Audio {
        id: playMusic
        source: "sources/grenada-grenada.mp3"
    }
    MouseArea {
        id: playArea
        anchors.fill: parent

        onPressed: {
            playMusic.play();
        }
    }
}