# загружаем изображение (cv2.imread()), показываем оригинал (cv2.imshow())
# размываем для подавление шума и переводим в HSV (cv2.cvtColor())
# ищем границы зелёного и создаём маску, показываем её
# находим зелёные контуры и через цикл, игнорируя шум, обрабатываем
# каждый зелёный объект, находя центр. в конце выводим результат
import cv2
import numpy as np
image = cv2.imread("test2.jpg")
cv2.imshow("original", image)
cv2.waitKey(0)
blurred_image = cv2.GaussianBlur(image, (11, 11), 0)
hsv_image = cv2.cvtColor(blurred_image, cv2.COLOR_BGR2HSV)
hsv_min = np.array((36, 25, 25), np.uint8)
hsv_max = np.array((70, 255, 255), np.uint8)
green_mask = cv2.inRange(hsv_image, hsv_min, hsv_max)
cv2.imshow("mask", green_mask)
cv2.waitKey(0)
contours, hierarchy = cv2.findContours(
    green_mask.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE
)
for contour in contours:
    if cv2.contourArea(contour) < 500:
        continue
    x, y, w, h = cv2.boundingRect(contour)
    cx = int(x + w / 2)
    cy = int(y + h / 2)
    print(f"Зелёный объект: x={x}, y={y}, w={w}, h={h}, центр=({cx}, {cy})")
    cv2.circle(image, (cx, cy), 10, (0, 0, 255), -1)
cv2.imshow("result", image)
cv2.waitKey(0)
cv2.destroyAllWindows()
