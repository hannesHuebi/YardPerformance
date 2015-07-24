import QtQuick 2.0
import Ubuntu.Components 1.1
import YardPerformace 1.0
/*!
    \brief MainView with a Label and Button elements.
*/


MainView {
    // objectName for functional testing purposes (autopilot-qt5)
    objectName: "mainView"

    // Note! applicationName needs to match the "name" field of the click manifest
    applicationName: "yardperformanceapp.hannes"

    /*
     This property enables the application to change orientation
     when the device is rotated. The default is false.
    */
    //automaticOrientation: true

    // Removes the old toolbar and enables new features of the new header.
    useDeprecatedToolbar: false

    width: units.gu(100)
    height: units.gu(75)

    Page {
        title: i18n.tr("YardPerformace")

        MyType {
            id: myType

            Component.onCompleted: {
                myType.helloWorld = i18n.tr("Hello world..")
            }
        }

        ParseCSV {
            id: parser

            Component.onCompleted: {
                parser.lenght = 2;
            }

        }

        Column {
            spacing: units.gu(1)
            anchors {
                margins: units.gu(2)
                fill: parent
            }

            Row{
                spacing: units.gu(1)
                Label{
                    text: "Minutes for Performance calculation:"
                }

                TextField{
                    id:xText
                    text: parser.lenght
                    onTextChanged: {
                        parser.lenght = parseInt(this.text)
                    }
                }
            }

            Label {
                id: label
                width: parent.width
                height: units.gu(10)
                objectName: "label"

                text: parser.volume;
                fontSize: qsTr("x-large")
                verticalAlignment: Text.AlignVCenter
                style: Text.Outline
                font.bold: true
                font.family: "Verdana"
                horizontalAlignment: Text.AlignHCenter
            }
            Button {
                objectName: "button"
                width: parent.width

                text: i18n.tr("Tap me!")

                onClicked: {


                    //                    parser.lenght = 5;
                    //                    parser.width = 5;
                    //                    parser.height = 5;

                    //                    var result = parser.volume;

                    //                    label.text = result;


                }
            }
        }
    }
}


