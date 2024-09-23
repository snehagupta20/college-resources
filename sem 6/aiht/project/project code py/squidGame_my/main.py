import pygame
import random
import time
import cv2
import numpy as np
from cvzone.FaceDetectionModule import FaceDetector
import serial


# ser = serial.Serial('COM5', 9600)
# time.sleep(2)
ws, hs = 1280, 720  # width and height
servoPos = [90, 90]  # initial servo position
prevCor = [-1, -1]

def send_coordinates(x, y):
    # Format coordinates as string and send over serial
    ser.write(f"{x} {y}\n".encode())

def play_song(song_path):
    # Initialize pygame
    pygame.init()

    try:
        # Load the song
        pygame.mixer.music.load(song_path)

        # Play the song
        pygame.mixer.music.play()

    except pygame.error as e:
        print("Error playing song:", e)

def play_shooting_sound():
    # Load the shooting sound
    shooting_sound = pygame.mixer.Sound("Files/gunshot.mp3")  # Replace this with the path to your shooting sound

    # Play the shooting sound
    shooting_sound.play()

def game():
    strike = 0
    detector = FaceDetector()
    cap = cv2.VideoCapture(0)
    if not cap.isOpened():
        print("Error: Unable to access the camera.")
        return
    gameOn = True
    song_path = "Files/bgm.mp3"  # Replace this with the path to your song
    play_song(song_path)

    try:
        pause_start_time = 0  # Variable to store the time when the song was paused
        while gameOn:
            ret, frame = cap.read()
            frame, bboxs = detector.findFaces(frame, draw=False)
            if not ret:
                print("Error: Unable to capture frame.")
                break

            if bboxs:
                # get the coordinate
                fx, fy = bboxs[0]["center"][0], bboxs[0]["center"][1]
                pos = [fx, fy]
                # convert coordinate to servo degree
                servoX = np.interp(fx, [0, ws], [180, 0])
                servoY = np.interp(fy, [0, hs], [180, 0])
                if servoX < 0:
                    servoX = 0
                elif servoX > 180:
                    servoX = 180
                if servoY < 0:
                    servoY = 0
                elif servoY > 180:
                    servoY = 180

                prevCor[0] = servoPos[0]
                prevCor[1] = servoPos[1]
                servoPos[0] = servoX
                servoPos[1] = servoY

                cv2.circle(frame, (int(fx), int(fy)), 80, (0, 0, 255), 2)
                cv2.putText(frame, str(pos), (int(fx) + 15, int(fy) - 15), cv2.FONT_HERSHEY_PLAIN, 2, (255, 0, 0), 2)
                cv2.line(frame, (0, int(fy)), (ws, int(fy)), (0, 0, 0), 2)  # x line
                cv2.line(frame, (int(fx), hs), (int(fx), 0), (0, 0, 0), 2)  # y line
                cv2.circle(frame, (int(fx), int(fy)), 5, (0, 0, 255), cv2.FILLED)
                cv2.putText(frame, "TARGET LOCKED", (850, 50), cv2.FONT_HERSHEY_PLAIN, 3, (255, 0, 255), 3)

            else:
                cv2.putText(frame, "NO TARGET", (880, 50), cv2.FONT_HERSHEY_PLAIN, 3, (0, 0, 255), 3)
                cv2.circle(frame, (640, 360), 80, (0, 0, 255), 2)
                cv2.circle(frame, (640, 360), 15, (0, 0, 255), cv2.FILLED)
                cv2.line(frame, (0, 360), (ws, 360), (0, 0, 0), 2)  # x line
                cv2.line(frame, (640, hs), (640, 0), (0, 0, 0), 2)  # y line

            cv2.putText(frame, f'Servo X: {int(servoPos[0])} deg', (50, 50), cv2.FONT_HERSHEY_PLAIN, 2, (255, 0, 0), 2)
            cv2.putText(frame, f'Servo Y: {int(servoPos[1])} deg', (50, 100), cv2.FONT_HERSHEY_PLAIN, 2, (255, 0, 0), 2)

            # Display the captured frame
            cv2.imshow('Camera Feed', frame)

            # Break the loop if 'q' is pressed
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break

            # Randomly pause the song
            rand = random.random()
            if rand  < 0.01:
                print("Pausing the song...")
                strike = 0
                pygame.mixer.music.pause()
                pause_start_time = time.time()  # Record the time when the song was paused

                # Wait until 5 seconds have passed
                while time.time() - pause_start_time < 5:
                    pygame.time.Clock().tick(10)

                print("Resuming the song...")
                pygame.mixer.music.unpause()

            else:
                if prevCor[0] != -1:
                    offset = ((prevCor[0] - servoPos[0]) * (prevCor[0] - servoPos[0])) + (
                                (prevCor[1] - servoPos[1]) * (prevCor[1] - servoPos[1]))
                    treshold = 5
                    if offset > treshold:
                        strike = strike + 1
                        if (strike > 1):
                            # send_coordinates(servoPos[0], servoPos[1])
                            play_shooting_sound()  # Play the shooting sound when offset exceeds threshold
                            break

            # Check if the song has finished playing
            if not pygame.mixer.music.get_busy():
                break  # Exit the loop if the song has finished

        cap.release()
        cv2.destroyAllWindows()
    except pygame.error as e:
        print("Error during game:", e)

    # Quit pygame
    pygame.quit()


if __name__ == "__main__":
    game()
