#ifndef QCMAINWINDOW_H
#define QCMAINWINDOW_H

#include "ui_QCMainWindow.h"
#include "bass.h"
#include "bass_fx.h"

#include <QMainWindow>
#include <QTime>

namespace Ui {
    class QCMainWindow;
}

class QCMainWindow: public QMainWindow, private Ui::QCMainWindow {
    Q_OBJECT

public:
    QCMainWindow(QWidget *parent = 0);
    QString filename_MP3;

protected:
    void changeEvent(QEvent *e);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

private:
    Ui::QCMainWindow *ui;
    QTime currentSongTimer;
    QTime currentNoteTimer;
    qint32 numSyllables;
    QString currentOutputTextLine;
    qint32 currentSyllableGlobalIndex;
    qint32 currentCharacterIndex;
    qint32 firstNoteStartBeat;
    qint32 currentNoteStartTime;
    qint32 currentNoteStartBeat;
    QString lyricsString;
    QStringList lyricsStringList;
    QClipboard *clipboard;
    double BPM;
    bool firstNote;
    QString cleanLyrics(QString);
    HSTREAM _mediaStream;
    void BASS_StopAndFree();
    void BASS_Play();
    void BASS_Pause();
    void BASS_Resume();
    double BASS_Position();
    void BASS_SetPosition(int seconds);
    void handleMP3();
    float playbackSpeedDecreasePercentage;

private slots:
    void on_horizontalSlider_PlaybackSpeed_valueChanged(int value);
    void on_actionGerman_triggered();
    void on_actionEnglish_triggered();
    void on_plainTextEdit_InputLyrics_textChanged();
    void on_pushButton_OutputLyricsDecreaseFontSize_clicked();
    void on_pushButton_OutputLyricsIncreaseFontSize_clicked();
    void on_pushButton_InputLyricsDecreaseFontSize_clicked();
    void on_pushButton_InputLyricsIncreaseFontSize_clicked();
    void on_pushButton_LoadFromFile_clicked();
    void on_comboBox_Genre_currentIndexChanged(QString );
    void on_doubleSpinBox_BPM_editingFinished();
    void on_lineEdit_Creator_editingFinished();
    void on_comboBox_Year_currentIndexChanged(QString );
    void on_comboBox_Edition_currentIndexChanged(QString );
    void on_comboBox_Language_currentIndexChanged(QString );
    void on_lineEdit_Title_editingFinished();
    void on_lineEdit_Artist_editingFinished();
    void on_actionAbout_Qt_triggered();
    void on_actionQuit_USC_triggered();
    void on_actionAbout_triggered();
    void on_pushButton_BrowseCover_clicked();
    void on_pushButton_BrowseVideo_clicked();
    void on_pushButton_BrowseBackground_clicked();
    void on_pushButton_BrowseMP3_clicked();
    void on_pushButton_Stop_clicked();
    void on_pushButton_CopyToClipboard_clicked();
    void on_pushButton_PasteFromClipboard_clicked();
    void on_pushButton_Tap_released();
    void on_pushButton_Tap_pressed();
    void on_pushButton_Start_clicked();
    bool on_pushButton_SaveToFile_clicked();
};

#endif // QCMAINWINDOW_H
